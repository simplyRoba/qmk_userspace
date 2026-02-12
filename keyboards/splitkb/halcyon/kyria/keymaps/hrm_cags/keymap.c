
#include QMK_KEYBOARD_H

enum layers {
    BASE = 0,   // default
    CST1,       // custom 1
    GAME,       // gaming
    NUMB,       // numbers & symbols
    FUNC,       // function
    NAVI,       // navigation
    MDIA,       // light & media
    SYST,       // system
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_5_hlc(
        KC_TAB,  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,                                                                KC_Y,            KC_U,         KC_I,         KC_O,         KC_P,            KC_BSLS,
        KC_ESC,  LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F), HYPR_T(KC_G),                                                        MEH_T(KC_H),     RSFT_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT,
        KC_BSPC, KC_Z,         KC_X,         KC_C,         KC_V,         LT(MDIA,KC_B),   KC_MINS,         KC_UP,   KC_DOWN, KC_EQL,          KC_N,            KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_BSPC,
                                             KC_CAPS,      KC_LBRC,      LT(NAVI,KC_ENT), LT(NUMB,KC_SPC), KC_RGHT, KC_LEFT, LT(NUMB,KC_SPC), LT(FUNC,KC_ENT), KC_RBRC,      MO(SYST),
        KC_ENT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [CST1] = LAYOUT_split_3x6_5_hlc(
        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [GAME] = LAYOUT_split_3x6_5_hlc(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                                    _______, _______, _______, _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                                    _______, _______, _______, _______, _______, _______,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LCTL, _______, _______, _______,                              _______, _______, _______, _______, _______, _______,
                                   KC_B,    KC_LCTL, KC_LALT, KC_SPC,  _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [NUMB] = LAYOUT_split_3x6_5_hlc(
        KC_GRV,  KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                                           KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,
        _______, KC_LCTL,    KC_LALT,    KC_LGUI,    KC_LSFT,    KC_HYPR,                                        KC_MEH,     KC_RSFT,    KC_RGUI,    KC_RALT,    KC_RCTL,    KC_EQL,
        _______, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), _______, _______, _______, _______, LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), _______,
                                         _______,    _______,    _______,    _______, _______, _______, _______, _______,    _______,    _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [FUNC] = LAYOUT_split_3x6_5_hlc(
        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                       KC_MEH,  KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, _______,
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [NAVI] = LAYOUT_split_3x6_5_hlc(
        _______, _______, LCTL(KC_LEFT), LGUI(KC_TAB), LCTL(KC_RGHT), LSG(KC_F12),                                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_INS,  _______,
        _______, KC_LCTL, KC_LALT,       KC_LGUI,      KC_LSFT,       KC_HYPR,                                         KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  _______,
        _______, _______, LGUI(KC_X),    LGUI(KC_C),   LGUI(KC_V),    _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                         _______,      _______,       _______,     _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [MDIA] = LAYOUT_split_3x6_5_hlc(
        _______, _______, _______, _______, _______, _______,                                     KC_PSCR, _______, KC_MUTE, _______, _______, _______,
        RM_HUEU, RM_SATU, RM_SPDU, RM_NEXT, RM_VALU, RM_TOGG,                                     KC_BRIU, KC_MPLY, KC_VOLU, KC_MSTP, _______, _______,
        RM_HUED, RM_SATD, RM_SPDD, RM_PREV, RM_VALD, _______, _______, _______, _______, _______, KC_BRID, KC_MPRV, KC_VOLD, KC_MNXT, _______, LCG(KC_Q),
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [SYST] = LAYOUT_split_3x6_5_hlc(
        _______, _______, _______, DF(BASE), _______, _______,                                     _______, _______, _______, _______, _______, QK_REBOOT,
        _______, _______, _______, DF(CST1), BL_UP,   BL_TOGG,                                     _______, _______, _______, _______, _______, QK_BOOTLOADER,
        _______, _______, _______, DF(GAME), BL_DOWN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_CLEAR_EEPROM,
                                   _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = {ENCODER_CCW_CW(KC_DOWN, KC_UP), ENCODER_CCW_CW(KC_DOWN, KC_UP), ENCODER_CCW_CW(KC_DOWN, KC_UP), ENCODER_CCW_CW(KC_DOWN, KC_UP)},
    [CST1] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [GAME] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [NUMB] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [FUNC] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [NAVI] = {ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
    [MDIA] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [SYST] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)}
};
#endif

// ---------------------------------------------------------------------------
// Per-layer RGB lighting
// ---------------------------------------------------------------------------

static void set_led_hsv(uint8_t index, uint8_t h, uint8_t s, uint8_t v) {
    HSV hsv = {h, s, (uint8_t)((uint16_t)v * rgb_matrix_get_val() / 255)};
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state);

    // BASE and CST1: let default animation run unchanged
    if (layer <= CST1) {
        return false;
    }

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t index = g_led_config.matrix_co[row][col];
            if (index == NO_LED || index < led_min || index >= led_max) {
                continue;
            }

            uint16_t keycode = keymap_key_to_keycode(layer, (keypos_t){col, row});

            // Transparent / empty keys go dark
            if (keycode == KC_TRNS || keycode == KC_NO) {
                rgb_matrix_set_color(index, 0, 0, 0);
                continue;
            }

            switch (layer) {

            // ── GAME (red) ──────────────────────────────────────
            case GAME:
                switch (keycode) {
                    case KC_W: case KC_A: case KC_S: case KC_D:
                        set_led_hsv(index, 0, 0, 255);       // white
                        break;
                    case KC_1: case KC_2: case KC_3: case KC_4: case KC_5:
                        set_led_hsv(index, 0, 82, 255);      // red
                        break;
                    case KC_Q: case KC_E: case KC_R: case KC_T:
                    case KC_G: case KC_B:
                        set_led_hsv(index, 0, 82, 170);      // red dim
                        break;
                    case KC_LSFT: case KC_LCTL: case KC_LALT: case KC_SPC:
                        set_led_hsv(index, 128, 255, 255);    // cyan
                        break;
                    default:
                        rgb_matrix_set_color(index, 0, 0, 0);
                        break;
                }
                break;

            // ── NUMB (yellow) ───────────────────────────────────
            case NUMB:
                switch (keycode) {
                    case KC_1: case KC_2: case KC_3: case KC_4: case KC_5:
                    case KC_6: case KC_7: case KC_8: case KC_9: case KC_0:
                    case KC_GRV: case KC_MINS: case KC_EQL:
                        set_led_hsv(index, 43, 71, 255);     // yellow
                        break;
                    case LSFT(KC_1): case LSFT(KC_2): case LSFT(KC_3):
                    case LSFT(KC_4): case LSFT(KC_5): case LSFT(KC_6):
                    case LSFT(KC_7): case LSFT(KC_8): case LSFT(KC_9):
                    case LSFT(KC_0):
                        set_led_hsv(index, 43, 71, 170);     // yellow dim
                        break;
                    case KC_LCTL: case KC_LALT: case KC_LGUI: case KC_LSFT:
                    case KC_RCTL: case KC_RALT: case KC_RGUI: case KC_RSFT:
                    case KC_HYPR: case KC_MEH:
                        set_led_hsv(index, 0, 0, 170);       // white dim
                        break;
                    default:
                        rgb_matrix_set_color(index, 0, 0, 0);
                        break;
                }
                break;

            // ── FUNC (green) ────────────────────────────────────
            case FUNC:
                switch (keycode) {
                    case KC_F1:  case KC_F2:  case KC_F3:  case KC_F4:
                    case KC_F5:  case KC_F6:  case KC_F7:  case KC_F8:
                    case KC_F9:  case KC_F10: case KC_F11: case KC_F12:
                        set_led_hsv(index, 77, 64, 255);     // green
                        break;
                    case KC_MEH: case KC_RSFT: case KC_RGUI:
                    case KC_RALT: case KC_RCTL:
                        set_led_hsv(index, 0, 0, 170);       // white dim
                        break;
                    default:
                        rgb_matrix_set_color(index, 0, 0, 0);
                        break;
                }
                break;

            // ── NAVI (blue) ─────────────────────────────────────
            case NAVI:
                switch (keycode) {
                    case KC_UP: case KC_DOWN: case KC_LEFT: case KC_RGHT:
                        set_led_hsv(index, 0, 0, 255);       // white
                        break;
                    case KC_PGUP: case KC_PGDN: case KC_HOME: case KC_END:
                        set_led_hsv(index, 176, 77, 255);    // blue
                        break;
                    case KC_INS: case KC_DEL:
                        set_led_hsv(index, 176, 77, 170);    // blue dim
                        break;
                    case LGUI(KC_X): case LGUI(KC_C): case LGUI(KC_V):
                        set_led_hsv(index, 77, 64, 255);     // green
                        break;
                    case LCTL(KC_LEFT): case LCTL(KC_RGHT): case LGUI(KC_TAB):
                        set_led_hsv(index, 176, 77, 170);    // blue dim
                        break;
                    case KC_LCTL: case KC_LALT: case KC_LGUI:
                    case KC_LSFT: case KC_HYPR:
                        set_led_hsv(index, 0, 0, 170);       // white dim
                        break;
                    default:
                        rgb_matrix_set_color(index, 0, 0, 0);
                        break;
                }
                break;

            // ── MDIA (teal) ─────────────────────────────────────
            case MDIA:
                switch (keycode) {
                    case RM_HUEU: case RM_HUED: case RM_SATU: case RM_SATD:
                    case RM_SPDU: case RM_SPDD: case RM_NEXT: case RM_PREV:
                    case RM_VALU: case RM_VALD: case RM_TOGG:
                    case KC_PSCR:
                        set_led_hsv(index, 131, 99, 255);    // teal
                        break;
                    case KC_MPLY: case KC_MSTP: case KC_MPRV:
                    case KC_MNXT: case KC_MUTE:
                        set_led_hsv(index, 0, 0, 255);       // white
                        break;
                    case KC_VOLU: case KC_VOLD:
                        set_led_hsv(index, 176, 77, 255);    // blue
                        break;
                    case KC_BRIU: case KC_BRID:
                        set_led_hsv(index, 43, 71, 255);     // yellow
                        break;
                    case LCG(KC_Q):
                        set_led_hsv(index, 0, 255, 255);     // red
                        break;
                    default:
                        rgb_matrix_set_color(index, 0, 0, 0);
                        break;
                }
                break;

            // ── SYST (purple) ───────────────────────────────────
            case SYST:
                switch (keycode) {
                    case DF(BASE): case DF(CST1): case DF(GAME):
                        set_led_hsv(index, 154, 94, 255);    // purple
                        break;
                    case BL_UP: case BL_DOWN: case BL_TOGG:
                        set_led_hsv(index, 0, 0, 170);       // white dim
                        break;
                    case QK_REBOOT: case QK_BOOTLOADER: case QK_CLEAR_EEPROM:
                        set_led_hsv(index, 0, 255, 255);     // red
                        break;
                    default:
                        rgb_matrix_set_color(index, 0, 0, 0);
                        break;
                }
                break;

            default:
                break;
            }
        }
    }

    return false;
}
