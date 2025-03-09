NEXTION_MOD_DIR := $(USERMOD_DIR)

# Add all C files to SRC_USERMOD.
SRC_USERMOD += $(wildcard $(NEXTION_MOD_DIR)/*.c)
SRC_USERMOD += $(wildcard $(NEXTION_MOD_DIR)/lib/nextion/*.c)


# We can add our module folder to include paths if needed
# This is not actually needed in this example.
# CFLAGS_USERMOD += -I$(NEXTION_MOD_DIR) -I$(NEXTION_MOD_DIR)/lib
CFLAGS_USERMOD += -I$(NEXTION_MOD_DIR) -I$(NEXTION_MOD_DIR)/lib
