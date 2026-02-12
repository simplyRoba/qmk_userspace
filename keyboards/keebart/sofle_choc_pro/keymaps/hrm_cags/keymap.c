
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
    [BASE] = LAYOUT_split_4x6_5(
        KC_GRV,  KC_1,         KC_2,         KC_3,         KC_4,         KC_5,                                     KC_6,         KC_7,         KC_8,         KC_9,         KC_0,            KC_MINS,
        KC_TAB,  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,                                     KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,            KC_BSLS,
        KC_ESC,  LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F), HYPR_T(KC_G),                             MEH_T(KC_H),  RSFT_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT,
        KC_BSPC, KC_Z,         KC_X,         KC_C,         KC_V,         LT(6,KC_B),   KC_ENT,       KC_ENT,       KC_N,         KC_M,         KC_COMM,      KC_DOT,       LT(7,KC_SLSH),   KC_BSPC,
                               KC_UP,        KC_DOWN,      KC_LBRC,      LT(5,KC_ENT), LT(3,KC_SPC), LT(3,KC_SPC), LT(4,KC_ENT), KC_RBRC,      KC_LEFT,      KC_RGHT
    ),
    [CST1] = LAYOUT_split_4x6_5(
        _______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______, _______, _______,  _______,_______,_______,_______,_______,_______,
                        _______,_______,_______,_______, _______, _______,  _______,_______,_______,_______
    ),
    [GAME] = LAYOUT_split_4x6_5(
        _______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,_______,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                  _______,_______,_______,_______,_______,_______,
        KC_LSFT,_______,_______,_______,_______, KC_B,    KC_LCTL, _______, _______,_______,_______,_______,_______,_______,
                        _______,_______, KC_LALT, KC_SPC,  KC_LCTL, _______, _______,_______,_______,_______
    ),
    [NUMB] = LAYOUT_split_4x6_5(
        _______,      _______,    _______,    _______,    _______,    _______,                      _______,    _______,    _______,    _______,    _______,    _______,
        LSFT(KC_GRV), LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),                   LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), LSFT(KC_MINS),
        _______,      KC_LCTL,    KC_LALT,    KC_LGUI,    KC_LSFT,    KC_HYPR,                      KC_MEH,     KC_RSFT,    KC_RGUI,    KC_RALT,    KC_RCTL,    KC_EQL,
        _______,      LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), _______, _______, LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), _______,
                                  _______,    _______,    _______,    _______,    _______, _______, _______,    _______,    _______,    _______
    ),
    [FUNC] = LAYOUT_split_4x6_5(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_MEH,  KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, _______,
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [NAVI] = LAYOUT_split_4x6_5(
        _______, _______, _______,       _______,      _______,        _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, LCTL(KC_LEFT), LGUI(KC_TAB), LCTL(KC_RGHT), LSG(KC_F12),                   KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_INS,  _______,
        _______, KC_LCTL, KC_LALT,       KC_LGUI,      KC_LSFT,       KC_HYPR,                       KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  _______,
        _______, _______, LGUI(KC_X),    LGUI(KC_C),   LGUI(KC_V),    _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                          _______,       _______,      _______,       _______,     _______, _______, _______, _______, _______, _______
    ),
    [MDIA] = LAYOUT_split_4x6_5(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   KC_PSCR, _______, KC_MUTE, _______, _______, _______,
        RM_HUEU, RM_SATU, RM_SPDU, RM_NEXT, RM_VALU, RM_TOGG,                   KC_BRIU, KC_MPLY, KC_VOLU, KC_MSTP, _______, _______,
        RM_HUED, RM_SATD, RM_SPDD, RM_PREV, RM_VALD, _______, _______, _______, KC_BRID, KC_MPRV, KC_VOLD, KC_MNXT, _______, LCG(KC_Q),
                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [SYST] = LAYOUT_split_4x6_5(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, DF(0),   _______, _______,                   _______, _______, _______, _______, _______, QK_REBOOT,
        _______, _______, _______, DF(1),   _______, _______,                   _______, _______, _______, _______, _______, QK_BOOTLOADER,
        _______, _______, _______, DF(2),   _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_CLEAR_EEPROM,
                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_DOWN, KC_UP) },
    [CST1] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [GAME] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [NUMB] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [FUNC] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [NAVI] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [MDIA] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [SYST] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) }
};
#endif
