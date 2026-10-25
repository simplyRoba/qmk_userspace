#pragma once

#undef PRODUCT
#define PRODUCT "Sofle Choc Pro"

#undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100

#define SPLIT_WATCHDOG_ENABLE
#undef RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT

#define TAPPING_TERM 190

// Prefer the character over its modifier or layer when pressed less than 100 ms after typing.
#define FLOW_TAP_TERM 100

// Activate the modifier or layer when another key is tapped while this key stays pressed.
#define PERMISSIVE_HOLD

// Keep quick overlapping letters on the same hand from activating modifiers.
#define CHORDAL_HOLD

#define RGB_MATRIX_TIMEOUT 300000
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_GRADIENT_UP_DOWN
#define RGB_MATRIX_DEFAULT_HUE 115
#define RGB_MATRIX_DEFAULT_SAT 255
#define RGB_MATRIX_DEFAULT_VAL 160
#define RGB_MATRIX_DEFAULT_SPD 80
