################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/DIO/subdir.mk
-include HAL/Transistor/subdir.mk
-include HAL/SevenSegmant/subdir.mk
-include HAL/OptoCoupler/subdir.mk
-include HAL/Motor/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KPD/subdir.mk
-include HAL/H_Bridge/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
H_bridge.lss \

FLASH_IMAGE += \
H_bridge.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: H_bridge.elf secondary-outputs

# Tool invocations
H_bridge.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,H_bridge.map -mmcu=atmega32 -o "H_bridge.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

H_bridge.lss: H_bridge.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S H_bridge.elf  >"H_bridge.lss"
	@echo 'Finished building: $@'
	@echo ' '

H_bridge.hex: H_bridge.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex H_bridge.elf  "H_bridge.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: H_bridge.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 H_bridge.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) H_bridge.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
