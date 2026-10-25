#pragma once

#define TAPPING_TERM 190

// Prefer the character over its modifier or layer when pressed less than 100 ms after typing.
#define FLOW_TAP_TERM 100

// Activate the modifier or layer when another key is tapped while this key stays pressed.
#define PERMISSIVE_HOLD

// Keep quick overlapping letters on the same hand from activating modifiers.
#define CHORDAL_HOLD

// Holding after a quick tap uses the modifier or layer instead of repeating the character.
#define QUICK_TAP_TERM 0

#define RGB_MATRIX_TIMEOUT 300000
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_GRADIENT_UP_DOWN
#define RGB_MATRIX_DEFAULT_HUE 200
#define RGB_MATRIX_DEFAULT_SAT 255
#define RGB_MATRIX_DEFAULT_VAL 160
#define RGB_MATRIX_DEFAULT_SPD 0
