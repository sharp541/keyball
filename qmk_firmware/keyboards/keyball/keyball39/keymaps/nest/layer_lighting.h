#include "quantum.h"

#define MAX_LEDS 48

const rgblight_segment_t PROGMEM default_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, MAX_LEDS, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM number_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, MAX_LEDS, HSV_BLUE}
);

const rgblight_segment_t PROGMEM symbol_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, MAX_LEDS, HSV_RED}
);

const rgblight_segment_t PROGMEM function_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, MAX_LEDS, HSV_YELLOW}
);

const rgblight_segment_t PROGMEM mouse_layer_vrt[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, MAX_LEDS, HSV_GREEN}
);

const rgblight_segment_t PROGMEM mouse_layer_hor[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, MAX_LEDS, HSV_ORANGE}
);

const rgblight_segment_t PROGMEM mouse_layer_fre[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, MAX_LEDS, HSV_PINK}
);

const rgblight_segment_t PROGMEM game_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, MAX_LEDS, HSV_WHITE}
);

enum layer_lighting_number {
    LAYER_LIGHTING_DEFAULT = 0,
    LAYER_LIGHTING_MOUSE_VRT,
    LAYER_LIGHTING_MOUSE_HOR,
    LAYER_LIGHTING_MOUSE_FRE,
    LAYER_LIGHTING_NUMBER,
    LAYER_LIGHTING_SYMBOL,
    LAYER_LIGHTING_FUNCTION,
    LAYER_LIGHTING_GAME
};


const rgblight_segment_t* const PROGMEM light_layers[] = {
    default_layer,
    mouse_layer_vrt,
    mouse_layer_hor,
    mouse_layer_fre,
    number_layer,
    symbol_layer,
    function_layer,
    game_layer
};
