/**
******************************************************************************
* @file    STM32Sensor.h
* @author  Jaume Gelabert
* @version V1.0.0
* @date    28-Mar-2025
 * @brief   This file contains definitions for the STM32Sensor.c firmware driver
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32SENSOR_H
#define __STM32SENSOR_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h> 
  

/** @addtogroup SDK_EVAL_BlueNRG1 SDK EVAL BlueNRG1
 * @{
 */

#ifndef NULL
  #define NULL      (void *) 0
#endif

/* STM32 sensor IO functions */
extern uint8_t STM32Sensor_IO_Init( void );
extern uint8_t STM32Sensor_IO_Read( uint8_t* pBuffer, uint8_t* dataType);


/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __STM32SENSOR_H */
