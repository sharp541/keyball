#include "custom_keys.h"

// ()
void paren_register(bool shifted) {
   if (shifted) {
      register_code16(KC_RPRN);
   } else {
      register_code16(KC_LPRN);
   }
}

void paren_unregister(bool shifted) {
   if (shifted) {
      unregister_code16(KC_RPRN);
   } else {
      unregister_code16(KC_LPRN);
   }
}

//{}
void brace_register(bool shifted) {
   if (shifted) {
      register_code16(KC_RCBR);
   } else {
      register_code16(KC_LCBR);
   }
}

void brace_unregister(bool shifted) {
   if (shifted) {
      unregister_code16(KC_RCBR);
   } else {
      unregister_code16(KC_LCBR);
   }
}

// []
void bracket_register(bool shifted) {
   if (shifted) {
      register_code16(KC_RBRC);
   } else {
      register_code16(KC_LBRC);
   }
}

void bracket_unregister(bool shifted) {
   if (shifted) {
      unregister_code16(KC_RBRC);
   } else {
      unregister_code16(KC_LBRC);
   }
}

// <>
void chevron_register(bool shifted) {
   if (shifted) {
      register_code16(KC_GT);
   } else {
      register_code16(KC_LT);
   }
}

void chevron_unregister(bool shifted) {
   if (shifted) {
      unregister_code16(KC_GT);
   } else {
      unregister_code16(KC_LT);
   }
}

void slash_register(bool shifted) {
   if (shifted) {
      register_code16(KC_BSLS);
   } else {
      register_code16(KC_SLSH);
   }
}

void slash_unregister(bool shifted) {
   if (shifted) {
      unregister_code16(KC_BSLS);
   } else {
      unregister_code16(KC_SLSH);
   }
}

void minus_register(bool shifted) {
   if (shifted) {
      register_code16(KC_TILD);
   } else {
      register_code16(KC_MINUS);
   }
}

void minus_unregister(bool shifted) {
   if (shifted) {
      unregister_code16(KC_TILD);
   } else {
      unregister_code16(KC_MINUS);
   }
}

void exclamation_register(bool shifted) {
   if (shifted) {
      tap_code16(KC_EXLM);
      register_code16(KC_EQL);
   } else {
      register_code16(KC_EXLM);
   }
}

void exclamation_unregister(bool shifted) {
   if (shifted) {
      unregister_code16(KC_EQL);
   } else {
      unregister_code16(KC_EXLM);
   }
}

void plus_register(bool shifted) {
   if (shifted) {
      tap_code16(KC_PLUS);
      register_code16(KC_EQL);
   } else {
      register_code16(KC_PLUS);
   }
}

void plus_unregister(bool shifted) {
   if (shifted) {
      unregister_code16(KC_EQL);
   } else {
      unregister_code16(KC_PLUS);
   }
}

void asterisk_register(bool shifted) {
   if (shifted) {
      tap_code16(KC_ASTR);
      register_code16(KC_EQL);
   } else {
      register_code16(KC_ASTR);
   }
}

void asterisk_unregister(bool shifted) {
   if (shifted) {
      unregister_code16(KC_EQL);
   } else {
      unregister_code16(KC_ASTR);
   }
}

void less_register(bool shifted) {
   if (shifted) {
      tap_code16(KC_LT);
      register_code16(KC_EQL);
   } else {
      register_code16(KC_LT);
   }
}

void less_unregister(bool shifted) {
   if (shifted) {
      unregister_code16(KC_EQL);
   } else {
      unregister_code16(KC_LT);
   }
}

void greater_register(bool shifted) {
   if (shifted) {
      tap_code16(KC_GT);
      register_code16(KC_EQL);
   } else {
      register_code16(KC_GT);
   }
}

void greater_unregister(bool shifted) {
   if (shifted) {
      unregister_code16(KC_EQL);
   } else {
      unregister_code16(KC_GT);
   }
}

const int all_key_count = 11;
const key_t **custom_keys = (const key_t *[]){
   // &(key_t){.custom_keycode = CKC_EN, .register_key = lang_en_register, .unregister_key = lang_en_unregister},
   // &(key_t){.custom_keycode = CKC_JA, .register_key = lang_ja_register, .unregister_key = lang_ja_unregister},
   &(key_t){.custom_keycode = CKC_PRN, .register_key = paren_register, .unregister_key = paren_unregister},
   &(key_t){.custom_keycode = CKC_BRC, .register_key = brace_register, .unregister_key = brace_unregister},
   &(key_t){.custom_keycode = CKC_BRCT, .register_key = bracket_register, .unregister_key = bracket_unregister},
   &(key_t){.custom_keycode = CKC_ABK, .register_key = chevron_register, .unregister_key = chevron_unregister},
   &(key_t){.custom_keycode = CKC_SL, .register_key = slash_register, .unregister_key = slash_unregister},
   &(key_t){.custom_keycode = CKC_MNS, .register_key = minus_register, .unregister_key = minus_unregister},
   &(key_t){.custom_keycode = CKC_EXC, .register_key = exclamation_register, .unregister_key = exclamation_unregister},
   &(key_t){.custom_keycode = CKC_PLS, .register_key = plus_register, .unregister_key = plus_unregister},
   &(key_t){.custom_keycode = CKC_AST, .register_key = asterisk_register, .unregister_key = asterisk_unregister},
   &(key_t){.custom_keycode = CKC_LES, .register_key = less_register, .unregister_key = less_unregister},
   &(key_t){.custom_keycode = CKC_GRT, .register_key = greater_register, .unregister_key = greater_unregister},
   NULL
};
