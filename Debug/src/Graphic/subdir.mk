################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Graphic/CSprite.cpp \
../src/Graphic/CTexture.cpp 

OBJS += \
./src/Graphic/CSprite.o \
./src/Graphic/CTexture.o 

CPP_DEPS += \
./src/Graphic/CSprite.d \
./src/Graphic/CTexture.d 


# Each subdirectory must supply rules for building sources it contributes
src/Graphic/%.o: ../src/Graphic/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DDEBUG -I"/home/zZelman/Dropbox/2D-GameEngine/SFML-2.1/include" -I"/home/zZelman/Dropbox/2D-GameEngine/rapidxml-1.13" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


