################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lcdlib.cpp 

OBJS += \
./lcdlib.o 

CPP_DEPS += \
./lcdlib.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Sourcery CodeBench C++ Compiler'
	arm-linux-gnueabihf-g++ -fPIC -I"/home/ngoc/workspace/gpiolib" -O0 -g3 -Wall -c -fmessage-length=0 -fcommon -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mfpu=vfp -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


