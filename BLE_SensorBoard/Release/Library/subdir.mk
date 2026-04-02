################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Library/BlueNRG1_adc.c \
../Library/BlueNRG1_dma.c \
../Library/BlueNRG1_flash.c \
../Library/BlueNRG1_gpio.c \
../Library/BlueNRG1_i2c.c \
../Library/BlueNRG1_mft.c \
../Library/BlueNRG1_pka.c \
../Library/BlueNRG1_rtc.c \
../Library/BlueNRG1_spi.c \
../Library/BlueNRG1_sysCtrl.c \
../Library/BlueNRG1_uart.c \
../Library/BlueNRG1_wdg.c \
../Library/misc.c 

OBJS += \
./Library/BlueNRG1_adc.o \
./Library/BlueNRG1_dma.o \
./Library/BlueNRG1_flash.o \
./Library/BlueNRG1_gpio.o \
./Library/BlueNRG1_i2c.o \
./Library/BlueNRG1_mft.o \
./Library/BlueNRG1_pka.o \
./Library/BlueNRG1_rtc.o \
./Library/BlueNRG1_spi.o \
./Library/BlueNRG1_sysCtrl.o \
./Library/BlueNRG1_uart.o \
./Library/BlueNRG1_wdg.o \
./Library/misc.o 

C_DEPS += \
./Library/BlueNRG1_adc.d \
./Library/BlueNRG1_dma.d \
./Library/BlueNRG1_flash.d \
./Library/BlueNRG1_gpio.d \
./Library/BlueNRG1_i2c.d \
./Library/BlueNRG1_mft.d \
./Library/BlueNRG1_pka.d \
./Library/BlueNRG1_rtc.d \
./Library/BlueNRG1_spi.d \
./Library/BlueNRG1_sysCtrl.d \
./Library/BlueNRG1_uart.d \
./Library/BlueNRG1_wdg.d \
./Library/misc.d 


# Each subdirectory must supply rules for building sources it contributes
Library/BlueNRG1_adc.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/Library/BlueNRG1_adc.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Library/BlueNRG1_dma.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/Library/BlueNRG1_dma.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Library/BlueNRG1_flash.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/Library/BlueNRG1_flash.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Library/BlueNRG1_gpio.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/Library/BlueNRG1_gpio.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Library/BlueNRG1_i2c.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/Library/BlueNRG1_i2c.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Library/BlueNRG1_mft.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/Library/BlueNRG1_mft.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Library/BlueNRG1_pka.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/Library/BlueNRG1_pka.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Library/BlueNRG1_rtc.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/Library/BlueNRG1_rtc.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Library/BlueNRG1_spi.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/Library/BlueNRG1_spi.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Library/BlueNRG1_sysCtrl.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/Library/BlueNRG1_sysCtrl.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Library/BlueNRG1_uart.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/Library/BlueNRG1_uart.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Library/BlueNRG1_wdg.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/Library/BlueNRG1_wdg.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Library/misc.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/Library/misc.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


