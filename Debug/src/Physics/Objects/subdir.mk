################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Physics/Objects/CCollidable.cpp \
../src/Physics/Objects/CGravityBased.cpp \
../src/Physics/Objects/CMovable.cpp 

OBJS += \
./src/Physics/Objects/CCollidable.o \
./src/Physics/Objects/CGravityBased.o \
./src/Physics/Objects/CMovable.o 

CPP_DEPS += \
./src/Physics/Objects/CCollidable.d \
./src/Physics/Objects/CGravityBased.d \
./src/Physics/Objects/CMovable.d 


# Each subdirectory must supply rules for building sources it contributes
src/Physics/Objects/%.o: ../src/Physics/Objects/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DDEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -I"/home/zZelman/Dropbox/2D-GameEngine/SFML-2.1/include" -I"/home/zZelman/Dropbox/2D-GameEngine/rapidxml-1.13" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


