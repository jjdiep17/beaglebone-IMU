################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../inv_mpu_lib/I2Cdev/I2Cdev.c 

OBJS += \
./inv_mpu_lib/I2Cdev/I2Cdev.o 

C_DEPS += \
./inv_mpu_lib/I2Cdev/I2Cdev.d 


# Each subdirectory must supply rules for building sources it contributes
inv_mpu_lib/I2Cdev/%.o: ../inv_mpu_lib/I2Cdev/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


