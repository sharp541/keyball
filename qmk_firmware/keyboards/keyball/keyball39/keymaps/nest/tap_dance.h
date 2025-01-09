#pragma once

#include "quantum.h"

//Tap dance enums
enum {
    FN_NUM_DEL = 0,  // 0x5700
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance (tap_dance_state_t *state);

void fn_num_del_finished (tap_dance_state_t *state, void *user_data);
void fn_num_del_reset (tap_dance_state_t *state, void *user_data);
