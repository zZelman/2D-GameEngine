################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Physics/CCollidable.cpp \
../src/Physics/CGravityBased.cpp \
../src/Physics/CMovable.cpp \
../src/Physics/PhysicsEngine.cpp 

OBJS += \
./src/Physics/CCollidable.o \
./src/Physics/CGravityBased.o \
./src/Physics/CMovable.o \
./src/Physics/PhysicsEngine.o 

CPP_DEPS += \
./src/Physics/CCollidable.d \
./src/Physics/CGravityBased.d \
./src/Physics/CMovable.d \
./src/Physics/PhysicsEngine.d 


# Each subdirectory must supply rules for building sources it contributes
src/Physics/%.o: ../src/Physics/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DDEBUG -I"/home/zZelman/Dropbox/2D-GameEngine/SFML-2.1/include" -I"/home/zZelman/Dropbox/2D-GameEngine/rapidxml-1.13" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


