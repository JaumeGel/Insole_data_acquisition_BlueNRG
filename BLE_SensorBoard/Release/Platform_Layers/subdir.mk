################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Platform_Layers/SDK_EVAL_Button.c \
../Platform_Layers/SDK_EVAL_Com.c \
../Platform_Layers/SDK_EVAL_Config.c \
../Platform_Layers/SDK_EVAL_I2C.c \
../Platform_Layers/SDK_EVAL_Led.c \
../Platform_Layers/SDK_EVAL_SPI.c \
../Platform_Layers/STM32Sensor.c 

OBJS += \
./Platform_Layers/SDK_EVAL_Button.o \
./Platform_Layers/SDK_EVAL_Com.o \
./Platform_Layers/SDK_EVAL_Config.o \
./Platform_Layers/SDK_EVAL_I2C.o \
./Platform_Layers/SDK_EVAL_Led.o \
./Platform_Layers/SDK_EVAL_SPI.o \
./Platform_Layers/STM32Sensor.o 

C_DEPS += \
./Platform_Layers/SDK_EVAL_Button.d \
./Platform_Layers/SDK_EVAL_Com.d \
./Platform_Layers/SDK_EVAL_Config.d \
./Platform_Layers/SDK_EVAL_I2C.d \
./Platform_Layers/SDK_EVAL_Led.d \
./Platform_Layers/SDK_EVAL_SPI.d \
./Platform_Layers/STM32Sensor.d 


# Each subdirectory must supply rules for building sources it contributes
Platform_Layers/SDK_EVAL_Button.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/Platform_Layers/SDK_EVAL_Button.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Platform_Layers/SDK_EVAL_Com.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/Platform_Layers/SDK_EVAL_Com.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Platform_Layers/SDK_EVAL_Config.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/Platform_Layers/SDK_EVAL_Config.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Platform_Layers/SDK_EVAL_I2C.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/Platform_Layers/SDK_EVAL_I2C.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Platform_Layers/SDK_EVAL_Led.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/Platform_Layers/SDK_EVAL_Led.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Platform_Layers/SDK_EVAL_SPI.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/Platform_Layers/SDK_EVAL_SPI.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Platform_Layers/STM32Sensor.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/Platform_Layers/STM32Sensor.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


