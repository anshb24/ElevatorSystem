.equ GPIO_OUTPUT_EN, 0x008 # Enable Output to selected pins
.equ GPIO_OUTPUT_VAL, 0x00C # Set Output Value
.equ GPIO_OUTPUT_XOR, 0x040 # inverse logic on selected pins
.equ GPIO_INPUT_EN, 0x04 # Set Input enable for selected pins
.equ GPIO_INPUT_VAL, 0x00 # Read Input value of selected pins
.equ GPIO_INPUT_PULUP, 0x10 # enable pull up
# 6 output pins for LEDs 2,3,4,5,6,7 (offset 18,19,20,21,22,23) 
.equ OUTPUT_PIN, (1U<<18|1U<<19|1U<<20|1U<<21|1U<<22|1U<<23)
# 6 input pins for pushbuttons -> 16,17,18,19,10,19 (Offset 10,11,12,13,2,9)
.equ INPUT_PIN, (1U<<10|1U<<11|1U<<12|1U<<13|1U<<2|1U<<1)
# .equ GPIO_RGB_PINS, 0x680000 # All 3 LED's bit offset
# .equ GPIO_RED_LED, 0x400000 # Red LED offset
# .equ GPIO_BLUE_LED, 0x200000 # Blue LED offset
# .equ GPIO_GREEN_LED, 0x080000 # Green LED offset