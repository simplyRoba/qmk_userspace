// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define SPLIT_POINTING_ENABLE

#define SPLIT_TRANSACTION_IDS_KB MODULE_SYNC

#include_next <mcuconf.h>

#undef RP_SPI_USE_SPI1
#define RP_SPI_USE_SPI1 TRUE

#undef RP_PWM_USE_PWM5
#define RP_PWM_USE_PWM5 TRUE

#define HAL_USE_PWM TRUE
#define HAL_USE_SPI TRUE
#define SPI_USE_WAIT TRUE
#define SPI_SELECT_MODE SPI_SELECT_MODE_PAD

#define POINTING_DEVICE_COMBINED

// Blank SPI config, otherwise a SPI module won't work as slave
#if !defined(HLC_SPI_DEVICE)
    #define SPI_SCK_PIN GP0 //NOT CONNECTED
    #define SPI_MOSI_PIN NO_PIN
    #define SPI_MISO_PIN NO_PIN

    #undef SPI_SELECT_MODE
    #define SPI_SELECT_MODE SPI_SELECT_MODE_NONE
#endif

#if !defined(HLC_TFT_DISPLAY)
    #define BACKLIGHT_PIN NO_PIN
    #define BACKLIGHT_PWM_DRIVER PWMD5
    #define BACKLIGHT_LEVELS 10
    #define BACKLIGHT_PWM_CHANNEL RP2040_PWM_CHANNEL_B
#endif

#if !defined(HLC_CIRQUE_TRACKPAD)
    #define POINTING_DEVICE_CS_PIN GP2 //NOT CONNECTED
#endif

#include_next <halconf.h>