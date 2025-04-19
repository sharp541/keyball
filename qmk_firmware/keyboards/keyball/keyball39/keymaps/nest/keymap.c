/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"
#include "layer.h"

#ifdef RGBLIGHT_ENABLE
#include "layer_lighting.h"
#endif

#ifdef TAP_DANCE_ENABLE
#include "tap_dance.h"
#endif

#ifdef KEY_OVERRIDE_ENABLE
#include "key_override.h"
#endif

#ifdef COMBO_ENABLE
#include "combo.h"
#endif

#include "custom_keys.h"

#define NUM_L LT(_NUMBER_LAYER,KC_TAB)
#define SYM_R LT(_SYMBOL_LAYER,KC_BSPC)
#define MO_RBTN LT(_MOUSE_LAYER,KC_BTN2)
#define FN_L LT(_FUNCTION_LAYER,KC_SPC)

// clang-format offLl
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT_LAYER] = LAYOUT_universal(
    KC_B     , KC_M     , KC_D     , KC_Z   , KC_X  ,                 KC_DOT  , KC_COMM , KC_E    , KC_P    , KC_V ,
    KC_S     , KC_K     , KC_T     , KC_N   , KC_L  ,                 KC_F    , KC_A    , KC_O    , KC_I    , KC_U ,
    KC_W     , KC_H     , KC_G     , KC_R   , KC_J  ,                 KC_Q    , KC_Y    , KC_BTN1 , MO_RBTN , KC_C ,
    _______  , _______  , _______  , FN_L   , NUM_L , _______,         RCTL_T(KC_DELETE) , SYM_R , _______ , _______ , _______ , CW_TOGG
  ),

  [_NUMBER_LAYER] = LAYOUT_universal(
    KC_5  , KC_6  , KC_7 , KC_8 , KC_9 ,                                    _______ , _______ , _______ , _______ , _______ ,
    KC_0  , KC_1  , KC_2 , KC_3 , KC_4   ,                                  _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , KC_COLN , KC_MINUS , KC_DOT     ,                   _______ , _______ , KC_BTN1 , KC_BTN2 , KC_BTN3 ,
    _______  , _______   , _______  , _______  , _______  , _______  ,      _______ , _______ , _______ , _______ , _______ , _______
  ),


  [_SYMBOL_LAYER] = LAYOUT_universal(
    KC_CIRC , _______ , KC_PERC , KC_AMPR , KC_PIPE ,                            KC_UNDS , CKC_BRC , CKC_LES  , CKC_GRT , KC_QUES ,
    KC_AT   , KC_HASH , KC_DLR  , CKC_AST , CKC_PLS ,                            CKC_MNS , CKC_PRN , CKC_BRCT , KC_COLN , KC_SCLN ,
    _______ , CKC_LES , CKC_GRT , CKC_EXC , KC_EQL  ,                            CKC_SL  , KC_DQT , KC_QUOT , KC_GRV , _______ ,
    _______ , _______ , _______ , KC_LNG2  , KC_LNG1  , _______  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),

  [_MOUSE_LAYER] = LAYOUT_universal(
    _______ , _______ , _______ , _______  , SGUI(KC_S) ,                      _______   , _______    , _______    , _______ , _______ ,
    C(KC_A) , C(KC_S) , C(KC_Z) , C(KC_Y)  , _______ ,                         SSNP_CYC  , C(KC_PGUP) , C(KC_PGDN) , _______ , _______  ,
    _______ , C(KC_X) , C(KC_C) , C(KC_V)  , _______ ,                         RCS(KC_T) , C(KC_T)    , C(KC_W)    , _______ , KC_BTN3 ,
    _______ , _______ , _______ , C(KC_SLSH)  , C(KC_LBRC)  , C(KC_RBRC)  ,      KC_BTN5  , KC_BTN4  , _______  , _______  , _______ , _______
  ),

  [_FUNCTION_LAYER] = LAYOUT_universal(
    KC_F5  , KC_F6  , KC_F7 , KC_F8 , KC_F9 ,                           CPI_D100 , CPI_I100 , SCRL_DVI , SCRL_DVD, QK_BOOT   ,
    KC_F10  , KC_F1  , KC_F2 , KC_F3 , KC_F4 ,                          _______ , _______ , _______ , _______, _______   ,
    _______ , _______ , _______ , KC_F12 , KC_F11     ,                 DF(_GAME_LAYER) , _______ , KC_BTN1 , KC_BTN2, KC_BTN3   ,
    _______  , _______   , _______  , _______  , KC_LSFT  , KC_BTN2  ,  _______ , _______ , _______ , _______, _______, _______
  ),
  [_GAME_LAYER] = LAYOUT_universal(
    KC_Q , KC_W , KC_E , KC_R , KC_T ,                                  KC_Y , KC_U , KC_I , KC_O , KC_P ,
    KC_A , KC_S , KC_D , KC_F , KC_G ,                                  KC_H , KC_J , KC_K , KC_L , KC_P ,
    KC_Z , KC_X , KC_C , KC_V , KC_B ,                                  KC_N , KC_M , KC_BTN1 , MO_RBTN , KC_BTN2 ,
    _______ , _______   , _______  , KC_BSPC  , KC_LSFT  , _______  ,  DF(_DEFAULT_LAYER) , KC_BTN2 , _______ , _______, _______, _______
  ),
};
// clang-format on

// COMBO
#ifdef COMBO_ENABLE
combo_t key_combos[] = {
    [ENT_R_COMBO] = COMBO(ent_r_combo, KC_ENT),
    [ENT_L_COMBO] = COMBO(ent_l_combo, SFT_T(KC_ENT)),
    [RARR_R_COMBO] = COMBO(rarr_r_combo, KC_RIGHT),
    [LARR_R_COMBO] = COMBO(larr_r_combo, KC_LEFT),
    [UARR_R_COMBO] = COMBO(uarr_r_combo, KC_UP),
    [DARR_R_COMBO] = COMBO(darr_r_combo, KC_DOWN),
    [DOT_R_COMBO] = COMBO(dot_r_combo, KC_DOT),
    [BSPC_R_COMBO] = COMBO(bspc_r_combo, C(KC_BSPC)),
    [BSPC_L_COMBO] = COMBO(bspc_l_combo, KC_BSPC),
    [HOME_R_COMBO] = COMBO(home_r_combo, KC_HOME),
    [END_R_COMBO] = COMBO(end_r_combo, KC_END),
    [ESC_R_COMBO] = COMBO(esc_r_combo, KC_ESC),
    [ALT_L_COMBO] = COMBO(alt_l_combo, KC_LALT),
    [GUI_L_COMBO] = COMBO(gui_l_combo, KC_LGUI),
    [CTRL_L_COMBO] = COMBO(ctrl_l_combo, KC_LCTL),
};
#endif

// Layer lighting
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_layers = light_layers;
#endif
}

bool led_update_user(led_t led_state) {
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    rgblight_set_layer_state(LAYER_LIGHTING_DEFAULT, layer_state_cmp(state, _DEFAULT_LAYER));
    rgblight_set_layer_state(LAYER_LIGHTING_GAME, layer_state_cmp(state, _GAME_LAYER));
    if (layer_state_cmp(state, _GAME_LAYER)) {
        autoshift_disable();
    } else {
        autoshift_enable();
    }
#endif
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    keyball_set_scroll_mode(get_highest_layer(state) == _MOUSE_LAYER);

    rgblight_set_layer_state(LAYER_LIGHTING_NUMBER, layer_state_cmp(state, _NUMBER_LAYER));
    rgblight_set_layer_state(LAYER_LIGHTING_SYMBOL, layer_state_cmp(state, _SYMBOL_LAYER));
    rgblight_set_layer_state(LAYER_LIGHTING_FUNCTION, layer_state_cmp(state, _FUNCTION_LAYER));
    rgblight_set_layer_state(LAYER_LIGHTING_GAME, layer_state_cmp(state, _GAME_LAYER));

    keyball_scrollsnap_mode_t mode = keyball_get_scrollsnap_mode();
    rgblight_set_layer_state(LAYER_LIGHTING_MOUSE_VRT, layer_state_cmp(state, _MOUSE_LAYER) && (mode == KEYBALL_SCROLLSNAP_MODE_VERTICAL));
    rgblight_set_layer_state(LAYER_LIGHTING_MOUSE_HOR, layer_state_cmp(state, _MOUSE_LAYER) && (mode == KEYBALL_SCROLLSNAP_MODE_HORIZONTAL));
    rgblight_set_layer_state(LAYER_LIGHTING_MOUSE_FRE, layer_state_cmp(state, _MOUSE_LAYER) && (mode == KEYBALL_SCROLLSNAP_MODE_FREE));
#endif
    return state;
}

// Tap dance
#ifdef TAP_DANCE_ENABLE
tap_dance_action_t tap_dance_actions[] = {
    [FN_NUM_DEL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,fn_num_del_finished, fn_num_del_reset),
};
#endif

// OLED
#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

static uint32_t key_timer;           // timer for last keyboard activity, use 32bit value and function to make longer idle time possible
static void refresh_rgb(void);       // refreshes the activity timer and RGB, invoke whenever any activity happens
static void check_rgb_timeout(void); // checks if enough time has passed for RGB to timeout

bool is_rgb_timeout = false;         // store if RGB has timed out or not in a boolean

void refresh_rgb(void) {
    key_timer = timer_read32(); // store time of last refresh
    if (is_rgb_timeout)
    {
        is_rgb_timeout = false;
        rgblight_wakeup();
    }
}
void check_rgb_timeout(void) {
    if (!is_rgb_timeout && timer_elapsed32(key_timer) > RGBLIGHT_TIMEOUT) // check if RGB has already timeout and if enough time has passed
    {
        rgblight_suspend();
        is_rgb_timeout = true;
    }
}

void housekeeping_task_user(void) {
#ifdef RGBLIGHT_TIMEOUT
    check_rgb_timeout();
#endif
}
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef RGBLIGHT_TIMEOUT
    if (record->event.pressed)
        refresh_rgb();
#endif
}
void post_encoder_update_user(uint8_t index, bool clockwise) {
#ifdef RGBLIGHT_TIMEOUT
    refresh_rgb();
#endif
}

static bool lang_en_state = true;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LNG1:
            if (record->event.pressed) {
                lang_en_state = false;
            }
            return true;
        case KC_LNG2:
            if (record->event.pressed) {
                lang_en_state = true;
            }
            return true;
        default:
            break;
    }
    return true;
}

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    for (int i = 0; i < all_key_count; i++) {
        const key_t *key = custom_keys[i];

        if (key->custom_keycode == keycode) {
            return true;
        }
    }

    if (lang_en_state) {
        switch (keycode) {
            case AUTO_SHIFT_ALPHA:
                return true;
            default:
                return false;
        }
    }
    return false;
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    for (int i = 0; i < all_key_count; i++) {
        const key_t *key = custom_keys[i];
        if (key->custom_keycode == keycode) {
            key->register_key(shifted);
            return;
        }
    }

    if (shifted) {
        add_weak_mods(MOD_BIT(KC_LSFT));
    }
    register_code16(keycode);
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    for (int i = 0; i < all_key_count; i++) {
        const key_t *key = custom_keys[i];
        if (key->custom_keycode == keycode) {
            key->unregister_key(shifted);
            return;
        }
    }

    unregister_code16(keycode);
}
