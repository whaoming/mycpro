################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/linelist/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
<<<<<<< HEAD
all: mycpro-master

# Tool invocations
mycpro-master: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MacOS X C Linker'
	gcc  -o "mycpro-master" $(OBJS) $(USER_OBJS) $(LIBS)
=======
all: mycpro

# Tool invocations
mycpro: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MacOS X C Linker'
	gcc  -o "mycpro" $(OBJS) $(USER_OBJS) $(LIBS)
>>>>>>> aaa30689e509707e21c41aa3665aeef19e5c5082
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
<<<<<<< HEAD
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) mycpro-master
=======
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) mycpro
>>>>>>> aaa30689e509707e21c41aa3665aeef19e5c5082
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
