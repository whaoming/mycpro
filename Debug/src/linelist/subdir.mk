################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/linelist/OrderList.c 

OBJS += \
./src/linelist/OrderList.o 

C_DEPS += \
./src/linelist/OrderList.d 


# Each subdirectory must supply rules for building sources it contributes
src/linelist/%.o: ../src/linelist/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


