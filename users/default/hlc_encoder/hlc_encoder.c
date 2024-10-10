// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "encoder.h"
#include "gpio.h"

#include "hlc_encoder.h"

static pin_t encoders_pad_a[NUM_ENCODERS_MAX_PER_SIDE] = ENCODER_A_PINS;
static pin_t encoders_pad_b[NUM_ENCODERS_MAX_PER_SIDE] = ENCODER_B_PINS;

void encoder_quadrature_init_pin(uint8_t index, bool pad_b) {
    pin_t pin = pad_b ? encoders_pad_b[index] : encoders_pad_a[index];
    encoders_pad_a[NUM_ENCODERS_MAX_PER_SIDE - 1] = HLC_ENCODER_A;
    encoders_pad_b[NUM_ENCODERS_MAX_PER_SIDE - 1] = HLC_ENCODER_B;
    if (pin != NO_PIN) {
        gpio_set_pin_input_high(pin);
    }
}

uint8_t encoder_quadrature_read_pin(uint8_t index, bool pad_b) {
    pin_t pin = pad_b ? encoders_pad_b[index] : encoders_pad_a[index];
    encoders_pad_a[NUM_ENCODERS_MAX_PER_SIDE - 1] = HLC_ENCODER_A;
    encoders_pad_b[NUM_ENCODERS_MAX_PER_SIDE - 1] = HLC_ENCODER_B;
    if (pin != NO_PIN) {
        return gpio_read_pin(pin) ? 1 : 0;
    }
    return 0;
}