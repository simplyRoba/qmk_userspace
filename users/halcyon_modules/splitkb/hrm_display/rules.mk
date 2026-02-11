SRC += $(USER_PATH)/splitkb/hrm_display/hrm_display.c
POST_CONFIG_H += $(USER_PATH)/splitkb/hrm_display/config.h

# Fonts
SRC += $(USER_PATH)/splitkb/hrm_display/graphics/fonts/Retron2000-27.qff.c \
       $(USER_PATH)/splitkb/hrm_display/graphics/fonts/Retron2000-underline-27.qff.c

# Layer icons in image format
SRC += $(USER_PATH)/splitkb/hrm_display/graphics/numbers/B.qgf.c \
	   $(USER_PATH)/splitkb/hrm_display/graphics/numbers/C.qgf.c \
	   $(USER_PATH)/splitkb/hrm_display/graphics/numbers/G.qgf.c \
	   $(USER_PATH)/splitkb/hrm_display/graphics/numbers/N.qgf.c \
	   $(USER_PATH)/splitkb/hrm_display/graphics/numbers/F.qgf.c \
	   $(USER_PATH)/splitkb/hrm_display/graphics/numbers/navi.qgf.c \
	   $(USER_PATH)/splitkb/hrm_display/graphics/numbers/M.qgf.c \
	   $(USER_PATH)/splitkb/hrm_display/graphics/numbers/S.qgf.c \
	   $(USER_PATH)/splitkb/hrm_display/graphics/numbers/undef.qgf.c
