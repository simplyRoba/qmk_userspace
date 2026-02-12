// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "halcyon.h"
#include "hrm_display.h"

// Letter layer icons
#include "graphics/numbers/B.qgf.h"
#include "graphics/numbers/C.qgf.h"
#include "graphics/numbers/G.qgf.h"
#include "graphics/numbers/N.qgf.h"
#include "graphics/numbers/F.qgf.h"
#include "graphics/numbers/navi.qgf.h"
#include "graphics/numbers/M.qgf.h"
#include "graphics/numbers/S.qgf.h"

// Undefined layer icon (from stock hlc_tft_display)
#include "hlc_tft_display/graphics/numbers/undef.qgf.h"

// Modifier icons (CAGS + caps lock)
#include "graphics/modifiers/ctrl.qgf.h"
#include "graphics/modifiers/alt.qgf.h"
#include "graphics/modifiers/gui.qgf.h"
#include "graphics/modifiers/shift.qgf.h"
#include "graphics/modifiers/caps.qgf.h"

// Modifier icon colors (HSV, all values 0-255)
#define HSV_MOD_ON  0, 0, 255
#define HSV_MOD_OFF 0, 0, 40

// Modifier icon positions (2x2 grid, 52x52 icons)
#define MOD_COL1_X 10
#define MOD_COL2_X 73
#define MOD_ROW1_Y 118
#define MOD_ROW2_Y 178

bool module_post_init_user(void) {
    return false;
}

bool display_module_housekeeping_task_user(bool second_display) {
    static layer_state_t last_layer_state = {0};
    static uint8_t last_mods = 0xFF;
    static bool last_caps = false;
    static bool first_run = false;

    if (!second_display) {
        // Layer letter icon
        if (last_layer_state != layer_state || !first_run) {
            painter_image_handle_t layer_number;

            switch (get_highest_layer(layer_state | default_layer_state)) {
            case 0:
                layer_number = qp_load_image_mem(gfx_B);
                qp_drawimage_recolor(lcd_surface, 30, 5, layer_number, HSV_LAYER_0, HSV_BLACK);
                break;
            case 1:
                layer_number = qp_load_image_mem(gfx_C);
                qp_drawimage_recolor(lcd_surface, 30, 5, layer_number, HSV_LAYER_1, HSV_BLACK);
                break;
            case 2:
                layer_number = qp_load_image_mem(gfx_G);
                qp_drawimage_recolor(lcd_surface, 30, 5, layer_number, HSV_LAYER_2, HSV_BLACK);
                break;
            case 3:
                layer_number = qp_load_image_mem(gfx_N);
                qp_drawimage_recolor(lcd_surface, 30, 5, layer_number, HSV_LAYER_3, HSV_BLACK);
                break;
            case 4:
                layer_number = qp_load_image_mem(gfx_F);
                qp_drawimage_recolor(lcd_surface, 30, 5, layer_number, HSV_LAYER_4, HSV_BLACK);
                break;
            case 5:
                layer_number = qp_load_image_mem(gfx_navi);
                qp_drawimage_recolor(lcd_surface, 30, 5, layer_number, HSV_LAYER_5, HSV_BLACK);
                break;
            case 6:
                layer_number = qp_load_image_mem(gfx_M);
                qp_drawimage_recolor(lcd_surface, 30, 5, layer_number, HSV_LAYER_6, HSV_BLACK);
                break;
            case 7:
                layer_number = qp_load_image_mem(gfx_S);
                qp_drawimage_recolor(lcd_surface, 30, 5, layer_number, HSV_LAYER_7, HSV_BLACK);
                break;
            default:
                layer_number = qp_load_image_mem(gfx_undef);
                qp_drawimage_recolor(lcd_surface, 30, 5, layer_number, HSV_LAYER_UNDEF, HSV_BLACK);
            }

            qp_close_image(layer_number);
            last_layer_state = layer_state;
        }

        // CAGS modifier indicators
        uint8_t current_mods = get_mods();
        bool current_caps = host_keyboard_led_state().caps_lock;

        if (current_mods != last_mods || current_caps != last_caps || !first_run) {
            painter_image_handle_t mod_icon;

            // Ctrl (top-left)
            mod_icon = qp_load_image_mem(gfx_ctrl);
            (current_mods & MOD_MASK_CTRL)
                ? qp_drawimage_recolor(lcd_surface, MOD_COL1_X, MOD_ROW1_Y, mod_icon, HSV_MOD_ON, HSV_BLACK)
                : qp_drawimage_recolor(lcd_surface, MOD_COL1_X, MOD_ROW1_Y, mod_icon, HSV_MOD_OFF, HSV_BLACK);
            qp_close_image(mod_icon);

            // Alt (top-right)
            mod_icon = qp_load_image_mem(gfx_alt);
            (current_mods & MOD_MASK_ALT)
                ? qp_drawimage_recolor(lcd_surface, MOD_COL2_X, MOD_ROW1_Y, mod_icon, HSV_MOD_ON, HSV_BLACK)
                : qp_drawimage_recolor(lcd_surface, MOD_COL2_X, MOD_ROW1_Y, mod_icon, HSV_MOD_OFF, HSV_BLACK);
            qp_close_image(mod_icon);

            // GUI (bottom-left)
            mod_icon = qp_load_image_mem(gfx_gui);
            (current_mods & MOD_MASK_GUI)
                ? qp_drawimage_recolor(lcd_surface, MOD_COL1_X, MOD_ROW2_Y, mod_icon, HSV_MOD_ON, HSV_BLACK)
                : qp_drawimage_recolor(lcd_surface, MOD_COL1_X, MOD_ROW2_Y, mod_icon, HSV_MOD_OFF, HSV_BLACK);
            qp_close_image(mod_icon);

            // Shift / Caps Lock (bottom-right)
            // Show caps lock icon when caps is on, shift icon otherwise
            if (current_caps) {
                mod_icon = qp_load_image_mem(gfx_caps);
                qp_drawimage_recolor(lcd_surface, MOD_COL2_X, MOD_ROW2_Y, mod_icon, HSV_MOD_ON, HSV_BLACK);
            } else {
                mod_icon = qp_load_image_mem(gfx_shift);
                (current_mods & MOD_MASK_SHIFT)
                    ? qp_drawimage_recolor(lcd_surface, MOD_COL2_X, MOD_ROW2_Y, mod_icon, HSV_MOD_ON, HSV_BLACK)
                    : qp_drawimage_recolor(lcd_surface, MOD_COL2_X, MOD_ROW2_Y, mod_icon, HSV_MOD_OFF, HSV_BLACK);
            }
            qp_close_image(mod_icon);

            last_mods = current_mods;
            last_caps = current_caps;
        }

        first_run = true;
    }

    // Write surface to physical LCD
    qp_surface_draw(lcd_surface, lcd, 0, 0, 0);

    return false;
}
