// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

// Stock hlc_tft_display/config.h provides LCD pin configuration and QP settings.
// Override the module identity so halcyon.c sets module = hrm_display.

#pragma once

#undef HLC_TFT_DISPLAY
#define HRM_DISPLAY
