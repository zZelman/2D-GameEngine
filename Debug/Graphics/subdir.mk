################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graphics/CSprite.cpp \
../Graphics/CTexture.cpp 

OBJS += \
./Graphics/CSprite.o \
./Graphics/CTexture.o 

CPP_DEPS += \
./Graphics/CSprite.d \
./Graphics/CTexture.d 


# Each subdirectory must supply rules for building sources it contributes
Graphics/%.o: ../Graphics/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DDEBUG -I"/home/zZelman/Dropbox/2D-GameEngine/SFML-2.1/include" -I"/home/zZelman/Dropbox/2D-GameEngine/rapidxml-1.13" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


