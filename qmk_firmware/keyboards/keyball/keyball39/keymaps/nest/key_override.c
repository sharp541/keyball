#include "quantum.h"
#include"key_override.h"
#include "custom_keys.h"

bool enable_autoshift(bool key_down, void *context){
    autoshift_enable();
    return true;
}

bool disable_autoshift(bool key_down, void *context){
    autoshift_disable();
    return true;
}

// language switch overrides
const key_override_t lang1_override = {
    .trigger = KC_LNG1,
    .replacement = KC_LNG1,
    .trigger_mods = 0,
    .layers = ~0,
    .suppressed_mods = 0,
    .options = ko_options_default,
    .negative_mod_mask = 0,
    .custom_action = disable_autoshift,
    .context = NULL,
    .enabled = NULL
};

const key_override_t lang2_override = {
    .trigger = KC_LNG2,
    .replacement = KC_LNG2,
    .trigger_mods = 0,
    .layers = ~0,
    .suppressed_mods = 0,
    .options = ko_options_default,
    .negative_mod_mask = 0,
    .custom_action = enable_autoshift,
    .context = NULL,
    .enabled = NULL
};

// list of key overrides
const key_override_t **key_overrides = (const key_override_t *[]){
    &lang1_override,
    &lang2_override,
    NULL
};
