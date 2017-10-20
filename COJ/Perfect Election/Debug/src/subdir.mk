################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Perfect\ Election.cpp 

OBJS += \
./src/Perfect\ Election.o 

CPP_DEPS += \
./src/Perfect\ Election.d 


# Each subdirectory must supply rules for building sources it contributes
src/Perfect\ Election.o: ../src/Perfect\ Election.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Perfect Election.d" -MT"src/Perfect\ Election.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


