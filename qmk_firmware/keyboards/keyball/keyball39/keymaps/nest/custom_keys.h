#pragma once

#include "quantum.h"

enum custom_keycodes {
    CKC_PRN = SAFE_RANGE,
    CKC_BRC,
    CKC_BRCT,
    CKC_ABK,
    CKC_SL,
    CKC_MNS,
    CKC_EXC,
    CKC_PLS,
    CKC_AST,
    CKC_LES,
    CKC_GRT
};

typedef struct {
    enum custom_keycodes custom_keycode;

    void (* register_key)(bool shifted);
    void (* unregister_key)(bool shifted);
} key_t;

extern const int all_key_count;
extern const key_t **custom_keys;
