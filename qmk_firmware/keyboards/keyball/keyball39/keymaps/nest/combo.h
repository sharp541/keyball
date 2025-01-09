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
    DARR_L_COMBO
};

// enter
const uint16_t PROGMEM ent_r_combo[] = {KC_N, KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM ent_l_combo[] = {KC_I, KC_A, KC_T, COMBO_END};

// right arrow
const uint16_t PROGMEM rarr_r_combo[] = {KC_P, KC_M, COMBO_END};
const uint16_t PROGMEM rarr_l_combo[] = {KC_Z, KC_S, COMBO_END};

// left arrow
const uint16_t PROGMEM larr_r_combo[] = {KC_P, KC_Y, COMBO_END};
const uint16_t PROGMEM larr_l_combo[] = {KC_Z, KC_J, COMBO_END};

// up arrow
const uint16_t PROGMEM uarr_r_combo[] = {KC_B, KC_G, COMBO_END};
const uint16_t PROGMEM uarr_l_combo[] = {KC_Q, KC_R, COMBO_END};

// down arrow
const uint16_t PROGMEM darr_r_combo[] = {KC_N, KC_B, KC_G, COMBO_END};
const uint16_t PROGMEM darr_l_combo[] = {KC_Q, KC_R, KC_A, COMBO_END};
