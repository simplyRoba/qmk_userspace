CURRENT_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))

CONFIG_H += $(CURRENT_DIR)/config.h