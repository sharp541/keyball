#pragma once

#include "custom_keys.h"

enum combos {
    ENT_R_COMBO,
    ENT_L_COMBO,
    RARR_R_COMBO,
    RARR_L_COMBO,
    LARR_R_COMBO,
    LARR_L_COMBO,
    UARR_R_COMBO,
    UARR_L_COMBO,
    DARR_R_COMBO,
    DARR_L_COMBO,
    DOT_R_COMBO,
    COMMA_COMBO,
    BSPC_R_COMBO,
    BSPC_L_COMBO,
    HOME_R_COMBO,
    END_R_COMBO,
    ESC_R_COMBO,
    ALT_L_COMBO,
    GUI_L_COMBO,
    CW_COMBO,
};

// enter
const uint16_t PROGMEM ent_r_combo[] = {KC_O, KC_I, COMBO_END};
const uint16_t PROGMEM ent_l_combo[] = {KC_S, KC_N, COMBO_END};

// right arrow
const uint16_t PROGMEM rarr_r_combo[] = {KC_X, KC_Y, COMBO_END};

// left arrow
const uint16_t PROGMEM larr_r_combo[] = {KC_X, KC_C, COMBO_END};

// up arrow
const uint16_t PROGMEM uarr_r_combo[] = {KC_E, KC_P, COMBO_END};

// down arrow
const uint16_t PROGMEM darr_r_combo[] = {KC_A, KC_E, KC_P, COMBO_END};

// dot
const uint16_t PROGMEM dot_r_combo[] = {KC_Y, KC_O, KC_I, COMBO_END};

// comma
const uint16_t PROGMEM comma_combo[] = {KC_M, KC_S, COMBO_END};

// backspace
const uint16_t PROGMEM bspc_r_combo[] = {KC_A, KC_O, KC_I, COMBO_END};
const uint16_t PROGMEM bspc_l_combo[] = {KC_K, KC_R, COMBO_END};

// home
const uint16_t PROGMEM home_r_combo[] = {KC_P, KC_V, COMBO_END};

// end
const uint16_t PROGMEM end_r_combo[] = {KC_O, KC_P, KC_V, COMBO_END};

// esc
const uint16_t PROGMEM esc_r_combo[] = {KC_I, KC_U, COMBO_END};

// alt
const uint16_t PROGMEM alt_l_combo[] = {KC_H, KC_K, COMBO_END};

// gui
const uint16_t PROGMEM gui_l_combo[] = {KC_F, KC_B, COMBO_END};

// caps word
const uint16_t PROGMEM cw_combo[] = {KC_Y, KC_D, COMBO_END};
