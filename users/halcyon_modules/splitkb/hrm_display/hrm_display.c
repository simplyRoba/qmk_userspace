// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "halcyon.h"
#include "hrm_display.h"

// Fonts mono2
#include "graphics/fonts/Retron2000-27.qff.h"
#include "graphics/fonts/Retron2000-underline-27.qff.h"

// Layer icons mono2
#include "graphics/numbers/B.qgf.h"
#include "graphics/numbers/C.qgf.h"
#include "graphics/numbers/G.qgf.h"
#include "graphics/numbers/N.qgf.h"
#include "graphics/numbers/F.qgf.h"
#include "graphics/numbers/navi.qgf.h"
#include "graphics/numbers/M.qgf.h"
#include "graphics/numbers/S.qgf.h"
#include "graphics/numbers/undef.qgf.h"

static const char *caps = "Caps";

static painter_font_handle_t Retron27;
static painter_font_handle_t Retron27_underline;
static painter_image_handle_t layer_number;

static uint8_t lcd_surface_fb[SURFACE_REQUIRED_BUFFER_BYTE_SIZE(135, 240, 16)];

painter_device_t lcd;
painter_device_t lcd_surface;

led_t last_led_usb_state = {0};
layer_state_t last_layer_state = {0};

void update_display(void) {
    static bool first_run_led = false;
    static bool first_run_layer = false;

    if(first_run_layer == false) {
        // Load fonts
        Retron27 = qp_load_font_mem(font_Retron2000_27);
        Retron27_underline = qp_load_font_mem(font_Retron2000_underline_27);
    }

    if(last_led_usb_state.raw != host_keyboard_led_state().raw || first_run_led == false) {
        led_t led_usb_state = host_keyboard_led_state();

        led_usb_state.caps_lock ? qp_drawtext_recolor(lcd_surface, 5, LCD_HEIGHT - Retron27->line_height - 5, Retron27_underline, caps, HSV_CAPS_ON, HSV_BLACK) : qp_drawtext_recolor(lcd_surface, 5, LCD_HEIGHT - Retron27->line_height - 5, Retron27, caps, HSV_CAPS_OFF, HSV_BLACK);

        last_led_usb_state = led_usb_state;
        first_run_led = true;
    }

    if(last_layer_state != layer_state || first_run_layer == false) {
        switch (get_highest_layer(layer_state|default_layer_state)) {
        case 0:
            layer_number = qp_load_image_mem(gfx_B);
            qp_drawimage_recolor(lcd_surface, 5, 5, layer_number, HSV_LAYER_0, HSV_BLACK);
            break;
        case 1:
            layer_number = qp_load_image_mem(gfx_C);
            qp_drawimage_recolor(lcd_surface, 5, 5, layer_number, HSV_LAYER_1, HSV_BLACK);
            break;
        case 2:
            layer_number = qp_load_image_mem(gfx_G);
            qp_drawimage_recolor(lcd_surface, 5, 5, layer_number, HSV_LAYER_2, HSV_BLACK);
            break;
        case 3:
            layer_number = qp_load_image_mem(gfx_N);
            qp_drawimage_recolor(lcd_surface, 5, 5, layer_number, HSV_LAYER_3, HSV_BLACK);
            break;
        case 4:
            layer_number = qp_load_image_mem(gfx_F);
            qp_drawimage_recolor(lcd_surface, 5, 5, layer_number, HSV_LAYER_4, HSV_BLACK);
            break;
        case 5:
            layer_number = qp_load_image_mem(gfx_navi);
            qp_drawimage_recolor(lcd_surface, 5, 5, layer_number, HSV_LAYER_5, HSV_BLACK);
            break;
        case 6:
            layer_number = qp_load_image_mem(gfx_M);
            qp_drawimage_recolor(lcd_surface, 5, 5, layer_number, HSV_LAYER_6, HSV_BLACK);
            break;
        case 7:
            layer_number = qp_load_image_mem(gfx_S);
            qp_drawimage_recolor(lcd_surface, 5, 5, layer_number, HSV_LAYER_7, HSV_BLACK);
            break;
        default:
            layer_number = qp_load_image_mem(gfx_undef);
            qp_drawimage_recolor(lcd_surface, 5, 5, layer_number, HSV_LAYER_UNDEF, HSV_BLACK);
        }
        qp_close_image(layer_number);
        last_layer_state = layer_state;
        first_run_layer = true;
    }
}

// Called from halcyon.c
void module_suspend_power_down_kb(void) {
    qp_power(lcd, false);
}

// Called from halcyon.c
void module_suspend_wakeup_init_kb(void) {
    qp_power(lcd, true);
}

// Called from halcyon.c
bool module_post_init_kb(void) {
    // Turn on backlight
    backlight_enable();

    // Make the devices
    lcd = qp_st7789_make_spi_device(LCD_WIDTH, LCD_HEIGHT, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, LCD_SPI_MODE);
    lcd_surface = qp_make_rgb565_surface(LCD_WIDTH, LCD_HEIGHT, lcd_surface_fb);

    // Initialise the LCD
    qp_init(lcd, LCD_ROTATION);
    qp_set_viewport_offsets(lcd, LCD_OFFSET_X, LCD_OFFSET_Y);
    qp_clear(lcd);
    qp_rect(lcd, 0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1, HSV_BLACK, true);
    qp_power(lcd, true);
    qp_flush(lcd);

    // Initialise the LCD surface
    qp_init(lcd_surface, LCD_ROTATION);
    qp_rect(lcd_surface, 0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1, HSV_BLACK, true);
    qp_surface_draw(lcd_surface, lcd, 0, 0, 0);
    qp_flush(lcd);

    if(!module_post_init_user()) { return false; }

    return true;
}

// Called from halcyon.c
bool display_module_housekeeping_task_kb(bool second_display) {
    if(!display_module_housekeeping_task_user(second_display)) { return false; }

    if(!second_display) {
        update_display();
    }

    // Move surface to lcd
    qp_surface_draw(lcd_surface, lcd, 0, 0, 0);
    qp_flush(lcd);

    return true;
}
