MCU := STM32F103RB
PRODUCT_ID := 0003
ERROR_LED_PORT := GPIOC
ERROR_LED_PIN := 12
DENSITY := STM32_MEDIUM_DENSITY
TARGET_FLAGS += -D$(DENSITY)
