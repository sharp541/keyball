#include "quantum.h"
#include "layer.h"
#include "tap_dance.h"

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else return TD_UNKNOWN;
}

// set LANG1 and enable auto shift
static td_tap_t fn_num_del_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void fn_num_del_finished (tap_dance_state_t *state, void *user_data) {
    fn_num_del_state.state = cur_dance(state);
    switch (fn_num_del_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_DELETE);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_NUMBER_LAYER);
            register_code(KC_RGUI);
            register_code(KC_RSFT);
            break;
        default: break;
    }
}

void fn_num_del_reset (tap_dance_state_t *state, void *user_data) {
    switch (fn_num_del_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_DELETE);
            break;
        case TD_SINGLE_HOLD:
            layer_off(_NUMBER_LAYER);
            unregister_code(KC_RGUI);
            unregister_code(KC_RSFT);
            break;
        default:
            break;
    }
    fn_num_del_state.state = TD_NONE;
}
