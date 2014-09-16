################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/LCDTest.cpp \
../src/SimpleGPIO.cpp \
../src/lcdlib.cpp 

OBJS += \
./src/LCDTest.o \
./src/SimpleGPIO.o \
./src/lcdlib.o 

CPP_DEPS += \
./src/LCDTest.d \
./src/SimpleGPIO.d \
./src/lcdlib.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Sourcery CodeBench C++ Compiler'
	arm-linux-gnueabihf-g++ -O0 -g3 -Wall -c -fmessage-length=0 -pthread -fcommon -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-a8 -mfpu=vfp --no-sysroot-suffix --sysroot= -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


