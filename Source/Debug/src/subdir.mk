################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/client.cpp \
../src/file_transmitter.cpp \
../src/relay.cpp \
../src/role.cpp \
../src/server.cpp 

OBJS += \
./src/client.o \
./src/file_transmitter.o \
./src/relay.o \
./src/role.o \
./src/server.o 

CPP_DEPS += \
./src/client.d \
./src/file_transmitter.d \
./src/relay.d \
./src/role.d \
./src/server.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -Wextra -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


