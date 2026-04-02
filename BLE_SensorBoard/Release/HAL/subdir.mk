################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../HAL/context_switch.s 

C_SRCS += \
../HAL/clock.c \
../HAL/miscutil.c \
../HAL/osal.c \
../HAL/sleep.c 

OBJS += \
./HAL/clock.o \
./HAL/context_switch.o \
./HAL/miscutil.o \
./HAL/osal.o \
./HAL/sleep.o 

S_DEPS += \
./HAL/context_switch.d 

C_DEPS += \
./HAL/clock.d \
./HAL/miscutil.d \
./HAL/osal.d \
./HAL/sleep.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/clock.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/HAL/clock.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

HAL/context_switch.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/HAL/context_switch.s
	@echo 'Building file: $<'
	@echo 'Invoking: GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

HAL/miscutil.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/HAL/miscutil.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

HAL/osal.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/HAL/osal.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

HAL/sleep.o: C:/Users/jaume/WiSE-Studio/workspace/BLE_Sensor_Jaume/BLE_SensorBoard/HAL/sleep.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -Os -ffunction-sections -fdata-sections -g3 -std=c99 -DLS_SOURCE=LS_SOURCE_EXTERNAL_32KHZ -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH -DBLUENRG2_DEVICE -DHS_SPEED_XTAL=HS_SPEED_XTAL_32MHZ -DUSER_BUTTON=BUTTON_2 -I../../include/inc -I../../include/Library/BLE_Application/OTA/inc -I../../include/Library/hal/inc -I../../include/Library/BlueNRG1_Periph_Driver/inc -I../../include/Library/CMSIS/Device/ST/BlueNRG1/Include -I../../include/Library/CMSIS/Include -I../../include/Library/Bluetooth_LE/inc -I../../include/Library/BLE_Application/layers_inc -I../../include/Library/BLE_Application/Utils/inc -I../../include/Library/SDK_Eval_BlueNRG1/inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


