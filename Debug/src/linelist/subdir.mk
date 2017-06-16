################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/linelist/LinkListOperaiotn.c \
../src/linelist/LinkListTest.c \
../src/linelist/OrderList.c \
../src/linelist/OrderListTest.c 

OBJS += \
./src/linelist/LinkListOperaiotn.o \
./src/linelist/LinkListTest.o \
./src/linelist/OrderList.o \
./src/linelist/OrderListTest.o 

C_DEPS += \
./src/linelist/LinkListOperaiotn.d \
./src/linelist/LinkListTest.d \
./src/linelist/OrderList.d \
./src/linelist/OrderListTest.d 


# Each subdirectory must supply rules for building sources it contributes
src/linelist/%.o: ../src/linelist/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


