################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/BlueNRG1_it.c \
../User/SensorDemo_main.c \
../User/gatt_db.c \
../User/sensor.c 

OBJS += \
./User/BlueNRG1_it.o \
./User/SensorDemo_main.o \
./User/gatt_db.o \
./User/sensor.o 

C_DEPS += \
./User/BlueNRG1_it.d \
./User/SensorDemo_main.d \
./User/gatt_db.d \
./User/sensor.d 


# Each subdirectory must supply rules for building sources it contributes
User/BlueNRG1_it.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/User/BlueNRG1_it.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

User/SensorDemo_main.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/User/SensorDemo_main.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

User/gatt_db.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/User/gatt_db.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

User/sensor.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/User/sensor.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


