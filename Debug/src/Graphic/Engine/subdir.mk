################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Graphic/Engine/RenderEngine.cpp 

OBJS += \
./src/Graphic/Engine/RenderEngine.o 

CPP_DEPS += \
./src/Graphic/Engine/RenderEngine.d 


# Each subdirectory must supply rules for building sources it contributes
src/Graphic/Engine/%.o: ../src/Graphic/Engine/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DDEBUG -D__GXX_EXPERIMENTAL_CXX0X__ -I"/home/zZelman/Dropbox/2D-GameEngine/SFML-2.1/include" -I"/home/zZelman/Dropbox/2D-GameEngine/rapidxml-1.13" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


