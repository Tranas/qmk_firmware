/*
Copyright 2018 Massdrop Inc.

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

#ifdef USE_MASSDROP_CONFIGURATOR

#    include "led_matrix.h"

// Teal <-> Salmon
led_setup_t leds_teal_salmon[] = {
    {.hs = 0, .he = 33, .rs = 24, .re = 24, .gs = 215, .ge = 215, .bs = 204, .be = 204, .ef = EF_NONE},
    {.hs = 33, .he = 66, .rs = 24, .re = 255, .gs = 215, .ge = 114, .bs = 204, .be = 118, .ef = EF_NONE},
    {.hs = 66, .he = 100, .rs = 255, .re = 255, .gs = 114, .ge = 114, .bs = 118, .be = 118, .ef = EF_NONE},
    {.end = 1},
};

// Yellow
led_setup_t leds_yellow[] = {
    {.hs = 0, .he = 100, .rs = 255, .re = 255, .gs = 255, .ge = 255, .bs = 0, .be = 0, .ef = EF_NONE},
    {.end = 1},
};

// Off
led_setup_t leds_off[] = {
    {.hs = 0, .he = 100, .rs = 0, .re = 0, .gs = 0, .ge = 0, .bs = 0, .be = 0, .ef = EF_NONE},
    {.end = 1},
};

// Red
led_setup_t leds_red[] = {
    {.hs = 0, .he = 100, .rs = 255, .re = 255, .gs = 0, .ge = 0, .bs = 0, .be = 0, .ef = EF_NONE},
    {.end = 1},
};

// Green
led_setup_t leds_green[] = {
    {.hs = 0, .he = 100, .rs = 0, .re = 0, .gs = 255, .ge = 255, .bs = 0, .be = 0, .ef = EF_NONE},
    {.end = 1},
};

// Blue
led_setup_t leds_blue[] = {
    {.hs = 0, .he = 100, .rs = 0, .re = 0, .gs = 0, .ge = 0, .bs = 255, .be = 255, .ef = EF_NONE},
    {.end = 1},
};

// White
led_setup_t leds_white[] = {
    {.hs = 0, .he = 100, .rs = 255, .re = 255, .gs = 255, .ge = 255, .bs = 255, .be = 255, .ef = EF_NONE},
    {.end = 1},
};

// White with moving red stripe
led_setup_t leds_white_with_red_stripe[] = {
    {.hs = 0, .he = 100, .rs = 255, .re = 255, .gs = 255, .ge = 255, .bs = 255, .be = 255, .ef = EF_NONE},
    {.hs = 0, .he = 15, .rs = 0, .re = 0, .gs = 0, .ge = 255, .bs = 0, .be = 255, .ef = EF_SCR_R | EF_SUBTRACT},
    {.hs = 15, .he = 30, .rs = 0, .re = 0, .gs = 255, .ge = 0, .bs = 255, .be = 0, .ef = EF_SCR_R | EF_SUBTRACT},
    {.end = 1},
};

// Black with moving red stripe
led_setup_t leds_black_with_red_stripe[] = {
    {.hs = 0, .he = 15, .rs = 0, .re = 255, .gs = 0, .ge = 0, .bs = 0, .be = 0, .ef = EF_SCR_R},
    {.hs = 15, .he = 30, .rs = 255, .re = 0, .gs = 0, .ge = 0, .bs = 0, .be = 0, .ef = EF_SCR_R},
    {.end = 1},
};

// Rainbow no scrolling
led_setup_t leds_rainbow_ns[] = {
    {.hs = 0, .he = 16.67, .rs = 255, .re = 255, .gs = 0, .ge = 255, .bs = 0, .be = 0, .ef = EF_OVER}, 
    {.hs = 16.67, .he = 33.33, .rs = 255, .re = 0, .gs = 255, .ge = 255, .bs = 0, .be = 0, .ef = EF_OVER}, 
    {.hs = 33.33, .he = 50, .rs = 0, .re = 0, .gs = 255, .ge = 255, .bs = 0, .be = 255, .ef = EF_OVER}, 
    {.hs = 50, .he = 66.67, .rs = 0, .re = 0, .gs = 255, .ge = 0, .bs = 255, .be = 255, .ef = EF_OVER}, 
    {.hs = 66.67, .he = 83.33, .rs = 0, .re = 255, .gs = 0, .ge = 0, .bs = 255, .be = 255, .ef = EF_OVER}, 
    {.hs = 83.33, .he = 100, .rs = 255, .re = 255, .gs = 0, .ge = 0, .bs = 255, .be = 0, .ef = EF_OVER}, 
    {.end = 1},
};

// Rainbow scrolling
led_setup_t leds_rainbow_s[] = {
    {.hs = 0, .he = 16.67, .rs = 255, .re = 255, .gs = 0, .ge = 255, .bs = 0, .be = 0, .ef = EF_OVER | EF_SCR_R}, 
    {.hs = 16.67, .he = 33.33, .rs = 255, .re = 0, .gs = 255, .ge = 255, .bs = 0, .be = 0, .ef = EF_OVER | EF_SCR_R}, 
    {.hs = 33.33, .he = 50, .rs = 0, .re = 0, .gs = 255, .ge = 255, .bs = 0, .be = 255, .ef = EF_OVER | EF_SCR_R}, 
    {.hs = 50, .he = 66.67, .rs = 0, .re = 0, .gs = 255, .ge = 0, .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R}, 
    {.hs = 66.67, .he = 83.33, .rs = 0, .re = 255, .gs = 0, .ge = 0, .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R}, 
    {.hs = 83.33, .he = 100, .rs = 255, .re = 255, .gs = 0, .ge = 0, .bs = 255, .be = 0, .ef = EF_OVER | EF_SCR_R}, 
    {.end = 1},
};

// Valhalla Theme Stripe Animation
led_setup_t leds_valhalla_stripe[] = {
    {.hs = 0, .he = 100, .rs = 0, .re = 0, .gs = 231, .ge = 231, .bs = 141, .be = 141, .ef = EF_NONE},
    {.hs = 0, .he = 33.33, .rs = 0, .re = 231, .gs = 0, .ge = 231, .bs = 0, .be = 51, .ef = EF_SCR_R | EF_SUBTRACT},
    {.hs = 33.33, .he = 66.67, .rs = 231, .re = 0, .gs = 231, .ge = 0, .bs = 51, .be = 0, .ef = EF_SCR_R | EF_SUBTRACT},
    {.end = 1},
};

// Vaporwave Stripe Animation [teal-pink]}
led_setup_t leds_vaporwave_stripe[] = {
    {.hs = 0, .he = 100, .rs = 0, .re = 0, .gs = 231, .ge = 231, .bs = 141, .be = 141, .ef = EF_NONE},
    {.hs = 0, .he = 33.33, .rs = 0, .re = 231, .gs = 231, .ge = 0, .bs = 141, .be = 90, .ef = EF_SCR_R | EF_SUBTRACT},
    {.hs = 33.33, .he = 66.67, .rs = 231, .re = 0, .gs = 0, .ge = 231, .bs = 90, .be = 141, .ef = EF_SCR_R | EF_SUBTRACT},
    {.end = 1},
};

// Vaporwave Stripe Animation [teal-purple]}
led_setup_t leds_vaporwave_stripe_purple[] = {
    {.hs = 0, .he = 100, .rs = 0, .re = 0, .gs = 231, .ge = 231, .bs = 141, .be = 141, .ef = EF_NONE},
    {.hs = 0, .he = 33.33, .rs = 0, .re = 141, .gs = 231, .ge = 0, .bs = 141, .be = 231, .ef = EF_SCR_R | EF_SUBTRACT},
    {.hs = 33.33, .he = 66.67, .rs = 141, .re = 0, .gs = 0, .ge = 231, .bs = 231, .be = 141, .ef = EF_SCR_R | EF_SUBTRACT},
    {.end = 1},
};


led_setup_t leds_valentine_stripe[] = {
    {.hs = 0, .he = 100, .rs = 231, .re = 231, .gs = 0, .ge = 0, .bs = 90, .be = 90, .ef = EF_NONE},
    {.hs = 0, .he = 33.33, .rs = 0, .re = 231, .gs = 231, .ge = 0, .bs = 141, .be = 90, .ef = EF_SCR_R | EF_SUBTRACT},
    {.hs = 33.33, .he = 66.67, .rs = 231, .re = 0, .gs = 0, .ge = 231, .bs = 90, .be = 141, .ef = EF_SCR_R | EF_SUBTRACT},
    {.end = 1},
};

led_setup_t leds_tetradic_teal[] = {
    {.hs = 0, .he = 25, .rs = 90, .re = 90, .gs = 231, .ge = 231, .bs = 0, .be = 0, .ef = EF_OVER | EF_SCR_R},
    {.hs = 25, .he = 50, .rs = 0, .re = 0, .gs = 231, .ge = 231, .bs = 141, .be = 141, .ef = EF_OVER | EF_SCR_R},
    {.hs = 50, .he = 75, .rs = 141, .re = 141, .gs = 0, .ge = 0, .bs = 231, .be = 231, .ef = EF_OVER | EF_SCR_R},
    {.hs = 75, .he = 100, .rs = 231, .re = 231, .gs = 0, .ge = 0, .bs = 90, .be = 90, .ef = EF_OVER | EF_SCR_R},
    {.end = 1},
};

led_setup_t leds_tetradic_teal_gradient[] = {
    {.hs = 0, .he = 25, .rs = 90, .re = 0, .gs = 231, .ge = 231, .bs = 0, .be = 141, .ef = EF_OVER | EF_SCR_R},
    {.hs = 25, .he = 50, .rs = 0, .re = 141, .gs = 231, .ge = 0, .bs = 141, .be = 231, .ef = EF_OVER | EF_SCR_R},
    {.hs = 50, .he = 75, .rs = 141, .re = 231, .gs = 0, .ge = 0, .bs = 231, .be = 90, .ef = EF_OVER | EF_SCR_R},
    {.hs = 75, .he = 100, .rs = 231, .re = 90, .gs = 0, .ge = 231, .bs = 90, .be = 0, .ef = EF_OVER | EF_SCR_R},
    {.end = 1},
};


led_setup_t leds_analogous_teal[] = {
    {.hs = 0, .he = 33.33, .rs = 0, .re = 0, .gs = 231, .ge = 231, .bs = 26, .be = 141, .ef = EF_OVER | EF_SCR_R},
    {.hs = 33.33, .he = 66.67, .rs = 0, .re = 0, .gs = 231, .ge = 206, .bs = 141, .be = 231, .ef = EF_OVER | EF_SCR_R},
    {.hs = 66.67, .he = 100, .rs = 0, .re = 0, .gs = 206, .ge = 231, .bs = 231, .be = 26, .ef = EF_OVER | EF_SCR_R},
    {.end = 1},
};

// Black with moving red stripe
led_setup_t leds_black_with_teal_stripe[] = {
    {.hs = 0, .he = 15, .rs = 0, .re = 0, .gs = 0, .ge = 231, .bs = 0, .be = 141, .ef = EF_SCR_R},
    {.hs = 15, .he = 30, .rs = 0, .re = 0, .gs = 231, .ge = 0, .bs = 141, .be = 0, .ef = EF_SCR_R},
    {.end = 1},
};

// Black with moving red stripe
led_setup_t leds_black_with_purple_stripe[] = {
    {.hs = 0, .he = 15, .rs = 0, .re = 141, .gs = 0, .ge = 0, .bs = 0, .be = 231, .ef = EF_SCR_R},
    {.hs = 15, .he = 30, .rs = 141, .re = 0, .gs = 0, .ge = 0, .bs = 231, .be = 0, .ef = EF_SCR_R},
    {.end = 1},
};

// Add new LED animations here using one from above as example
// The last entry must be { .end = 1 }
// Add the new animation name to the list below following its format

void *led_setups[] = {
    // leds_off,
    leds_valhalla_stripe, 
    leds_vaporwave_stripe,
    leds_vaporwave_stripe_purple,
    leds_valentine_stripe,
    leds_tetradic_teal,
    leds_tetradic_teal_gradient,
    leds_analogous_teal,
    // leds_rainbow_s,
    // leds_rainbow_ns,
    // leds_teal_salmon, 
    // leds_yellow, 
    // leds_red, 
    // leds_green, 
    // leds_blue, 
    // leds_white, 
    // leds_white_with_red_stripe, 
    leds_black_with_red_stripe,
    leds_black_with_teal_stripe,
    leds_black_with_purple_stripe
    };

const uint8_t led_setups_count = sizeof(led_setups) / sizeof(led_setups[0]);

#endif
