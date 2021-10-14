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
OptoCoupler.lss \

FLASH_IMAGE += \
OptoCoupler.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: OptoCoupler.elf secondary-outputs

# Tool invocations
OptoCoupler.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,OptoCoupler.map -mmcu=atmega32 -o "OptoCoupler.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

OptoCoupler.lss: OptoCoupler.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S OptoCoupler.elf  >"OptoCoupler.lss"
	@echo 'Finished building: $@'
	@echo ' '

OptoCoupler.hex: OptoCoupler.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex OptoCoupler.elf  "OptoCoupler.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: OptoCoupler.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 OptoCoupler.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) OptoCoupler.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
