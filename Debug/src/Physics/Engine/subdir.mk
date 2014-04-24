################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Physics/Engine/PhysicsEngine.cpp 

OBJS += \
./src/Physics/Engine/PhysicsEngine.o 

CPP_DEPS += \
./src/Physics/Engine/PhysicsEngine.d 


# Each subdirectory must supply rules for building sources it contributes
src/Physics/Engine/%.o: ../src/Physics/Engine/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DDEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -I"/home/zZelman/Dropbox/2D-GameEngine/SFML-2.1/include" -I"/home/zZelman/Dropbox/2D-GameEngine/rapidxml-1.13" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


