CURRENT_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))

SRC += $(CURRENT_DIR)/hlc_encoder.c $(CURRENT_DIR)/hlc_encoder_matrix.c
CONFIG_H += $(CURRENT_DIR)/config.h