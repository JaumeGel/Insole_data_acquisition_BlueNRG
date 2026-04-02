/**
 * @file    STM32Sensor_hal.h
 * @author  Jaume Gelabert
 * @version V1.0.0
 * @date    March 28, 2026
 * @brief   This file provides all the low level API to manage STM32 comm in board.
 * @details
*/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32SENSOR_HAL_H
#define __STM32SENSOR_HAL_H

/* Includes ------------------------------------------------------------------*/
#include "SDK_EVAL_SPI.h"
#include "STM32Sensor.h"
   
   
#ifdef __cplusplus
 extern "C" {
#endif



#define STM32_IRQ_PIN                      SDK_EVAL_IRQ_SENSOR_PIN
#define STM32_SPI_FREQUENCY                (1000000)

/**
 * @}
 */

#define STM32Sensor_IO_Init()						SdkEvalSpiInit(STM32_SPI_FREQUENCY)
#define STM32Sensor_IO_Read(pBuffer, dataType)		SdkEvalSpiRead(pBuffer, dataType)

   
#ifdef __cplusplus
}
#endif

#endif
