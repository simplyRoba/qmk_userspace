CURRENT_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))

SRC += $(CURRENT_DIR)/hlc_tft_display.c
CONFIG_H += $(CURRENT_DIR)/config.h

# Fonts
SRC += $(CURRENT_DIR)/graphics/fonts/Retron2000-27.qff.c $(CURRENT_DIR)/graphics/fonts/Retron2000-underline-27.qff.c
# Numbers in image format
SRC += $(CURRENT_DIR)/graphics/numbers/0.qgf.c $(CURRENT_DIR)/graphics/numbers/1.qgf.c $(CURRENT_DIR)/graphics/numbers/2.qgf.c $(CURRENT_DIR)/graphics/numbers/3.qgf.c $(CURRENT_DIR)/graphics/numbers/4.qgf.c $(CURRENT_DIR)/graphics/numbers/5.qgf.c $(CURRENT_DIR)/graphics/numbers/6.qgf.c $(CURRENT_DIR)/graphics/numbers/7.qgf.c $(CURRENT_DIR)/graphics/numbers/8.qgf.c $(CURRENT_DIR)/graphics/numbers/9.qgf.c $(CURRENT_DIR)/graphics/numbers/undef.qgf.c
