# Standard things
sp              := $(sp).x
dirstack_$(sp)  := $(d)
d               := $(dir)
BUILDDIRS       += $(BUILD_PATH)/$(d)

LIBMAPLE_INCLUDES := -I$(LIBMAPLE_PATH)/include -I$(LIBMAPLE_MODULE_SERIES)/include
LIBMAPLE_PRIVATE_INCLUDES := -I$(LIBMAPLE_PATH)

# Local flags
CFLAGS_$(d) = $(LIBMAPLE_PRIVATE_INCLUDES) $(LIBMAPLE_INCLUDES) -Wall -Werror

# Local rules and targets
cSRCS_$(d) := flash.c                  \
              gpio.c                   \
              nvic.c                   \
              rcc.c                    \
              syscalls.c               \
              systick.c                \
              util.c

sSRCS_$(d) := exc.S

cFILES_$(d) := $(cSRCS_$(d):%=$(d)/%)
sFILES_$(d) := $(sSRCS_$(d):%=$(d)/%)

OBJS_$(d) := $(cFILES_$(d):%.c=$(BUILD_PATH)/%.o) $(sFILES_$(d):%.S=$(BUILD_PATH)/%.o)
DEPS_$(d) := $(OBJS_$(d):%.o=%.d)

$(OBJS_$(d)): TGT_CFLAGS := $(CFLAGS_$(d))
$(OBJS_$(d)): TGT_ASFLAGS :=

TGT_BIN += $(OBJS_$(d))

# Standard things
-include        $(DEPS_$(d))
d               := $(dirstack_$(sp))
sp              := $(basename $(sp))
