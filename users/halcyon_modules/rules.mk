# Add this to your existing rules.mk if you have one
ifneq ($(filter $(strip $(KEYBOARD)), splitkb/halcyon/kyria/rev4 \
                                      splitkb/halcyon/ferris/rev1),)
	include $(USER_PATH)/splitkb/rules.mk
endif
