# Build on top of stock hlc_tft_display module
include $(USER_PATH)/splitkb/hlc_tft_display/rules.mk

# Override module identity (must come after stock config.h in POST_CONFIG_H)
POST_CONFIG_H += $(USER_PATH)/splitkb/hrm_display/config.h

# Custom display implementation (overrides _user functions)
SRC += $(USER_PATH)/splitkb/hrm_display/hrm_display.c

# Layer icons
SRC += $(USER_PATH)/splitkb/hrm_display/graphics/layers/B.qgf.c \
       $(USER_PATH)/splitkb/hrm_display/graphics/layers/C.qgf.c \
       $(USER_PATH)/splitkb/hrm_display/graphics/layers/G.qgf.c \
       $(USER_PATH)/splitkb/hrm_display/graphics/layers/N.qgf.c \
       $(USER_PATH)/splitkb/hrm_display/graphics/layers/F.qgf.c \
       $(USER_PATH)/splitkb/hrm_display/graphics/layers/navi.qgf.c \
       $(USER_PATH)/splitkb/hrm_display/graphics/layers/M.qgf.c \
       $(USER_PATH)/splitkb/hrm_display/graphics/layers/S.qgf.c

# Modifier icons (CAGS)
SRC += $(USER_PATH)/splitkb/hrm_display/graphics/modifiers/ctrl.qgf.c \
       $(USER_PATH)/splitkb/hrm_display/graphics/modifiers/alt.qgf.c \
       $(USER_PATH)/splitkb/hrm_display/graphics/modifiers/gui.qgf.c \
       $(USER_PATH)/splitkb/hrm_display/graphics/modifiers/shift.qgf.c \
       $(USER_PATH)/splitkb/hrm_display/graphics/modifiers/caps.qgf.c
