# May need to be changed when adding more pointing devices
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = cirque_pinnacle_spi

# May need to be changed when adding more displays
QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS += st7789_spi surface

BACKLIGHT_ENABLE = yes
BACKLIGHT_DRIVER = pwm

VPATH += $(USER_PATH)/splitkb/
SRC += $(USER_PATH)/splitkb/halcyon.c
HALCONFDIR += $(USER_PATH)/splitkb/halconf.h
POST_CONFIG_H += $(USER_PATH)/splitkb/config.h

ifdef HLC_ENCODER
  include $(USER_PATH)/splitkb/hlc_encoder/rules.mk
endif

ifdef HLC_TFT_DISPLAY
  include $(USER_PATH)/splitkb/hlc_tft_display/rules.mk
endif

ifdef HLC_CIRQUE_TRACKPAD
  include $(USER_PATH)/splitkb/hlc_cirque_trackpad/rules.mk
endif

ifdef HRM_DISPLAY
  include $(USER_PATH)/splitkb/hrm_display/rules.mk
endif

HLC_OPTIONS := $(HLC_NONE) $(HLC_CIRQUE_TRACKPAD) $(HLC_ENCODER) $(HLC_TFT_DISPLAY) $(HRM_DISPLAY)

ifeq ($(filter 1, $(HLC_OPTIONS)), )
$(error Halcyon_modules used but wrong or no module specified. Please specify one by adding `-e <module_name>=1` to your compile command where <module_name> can be: HLC_NONE, HLC_CIRQUE_TRACKPAD, HLC_ENCODER, HLC_TFT_DISPLAY, HRM_DISPLAY)
endif
