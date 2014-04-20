################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GameElement_gravity.cpp \
../src/GameElement_movable.cpp \
../src/GameElement_static.cpp \
../src/main.cpp 

OBJS += \
./src/GameElement_gravity.o \
./src/GameElement_movable.o \
./src/GameElement_static.o \
./src/main.o 

CPP_DEPS += \
./src/GameElement_gravity.d \
./src/GameElement_movable.d \
./src/GameElement_static.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DDEBUG -I"/home/zZelman/Dropbox/2D-GameEngine/SFML-2.1/include" -I"/home/zZelman/Dropbox/2D-GameEngine/rapidxml-1.13" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


