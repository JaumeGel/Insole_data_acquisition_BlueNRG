/******************** (C) COPYRIGHT 2015 STMicroelectronics ********************
* File Name          : gatt_db.c
* Author             : BlueNRG-1 main file for Chat demo
* Version            : V1.0.0
* Date               : 16-September-2015
* Description        : Functions to build GATT DB and handle GATT events.
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BlueNRG1_it.h"
#include "BlueNRG1_conf.h"
#include "ble_const.h" 
#include "bluenrg1_stack.h"
#include "clock.h"
#include "gp_timer.h"
#include "gatt_db.h"
#include "osal.h"
#include "SDK_EVAL_Config.h"

#include "STM32Sensor_hal.h"
#include "STM32Sensor.h"

#ifndef DEBUG
#define DEBUG 0
#endif

#if DEBUG
#include <stdio.h>
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...)
#endif


#define COPY_UUID_128(uuid_struct, uuid_15, uuid_14, uuid_13, uuid_12, uuid_11, uuid_10, uuid_9, uuid_8, uuid_7, uuid_6, uuid_5, uuid_4, uuid_3, uuid_2, uuid_1, uuid_0) \
do {\
    uuid_struct[0] = uuid_0; uuid_struct[1] = uuid_1; uuid_struct[2] = uuid_2; uuid_struct[3] = uuid_3; \
        uuid_struct[4] = uuid_4; uuid_struct[5] = uuid_5; uuid_struct[6] = uuid_6; uuid_struct[7] = uuid_7; \
            uuid_struct[8] = uuid_8; uuid_struct[9] = uuid_9; uuid_struct[10] = uuid_10; uuid_struct[11] = uuid_11; \
                uuid_struct[12] = uuid_12; uuid_struct[13] = uuid_13; uuid_struct[14] = uuid_14; uuid_struct[15] = uuid_15; \
}while(0)


#define COPY_RES_SERVICE_UUID(uuid_struct)  COPY_UUID_128(uuid_struct,0x02,0x36,0x6e,0x80, 0xcf,0x3a, 0x11,0xe1, 0x9a,0xb4, 0x00,0x02,0xa5,0xd5,0xc5,0x1b)
#define COPY_RES1_CHAR_UUID(uuid_struct)	COPY_UUID_128(uuid_struct,0x00,0x00,0x00,0x00, 0x00,0x01, 0x11,0xe1, 0xac,0x36, 0x00,0x02,0xa5,0xd5,0xc5,0x1b)
#define COPY_RES2_CHAR_UUID(uuid_struct)	COPY_UUID_128(uuid_struct,0x00,0xE0,0x00,0x00, 0x00,0x01, 0x11,0xe1, 0xac,0x36, 0x00,0x02,0xa5,0xd5,0xc5,0x1b)

#define COPY_CAP_SERVICE_UUID(uuid_struct)	COPY_UUID_128(uuid_struct,0x42,0x82,0x1a,0x40, 0xe4,0x77, 0x11,0xe2, 0x82,0xd0, 0x00,0x02,0xa5,0xd5,0xc5,0x1b)
#define COPY_CAP1_CHAR_UUID(uuid_struct)	COPY_UUID_128(uuid_struct,0x01,0xC0,0x00,0x00,0x00,0x01, 0x11,0xe2, 0xac,0x36, 0x00,0x02,0xa5,0xd5,0xc5,0x1b)
#define COPY_CAP2_CHAR_UUID(uuid_struct)	COPY_UUID_128(uuid_struct,0x02,0xA0,0x00,0x00,0x00,0x01, 0x11,0xe2, 0xac,0x36, 0x00,0x02,0xa5,0xd5,0xc5,0x1b)
#define COPY_CAP3_CHAR_UUID(uuid_struct)	COPY_UUID_128(uuid_struct,0x03,0x80,0x00,0x00,0x00,0x01, 0x11,0xe2, 0xac,0x36, 0x00,0x02,0xa5,0xd5,0xc5,0x1b)
#define COPY_CAP4_CHAR_UUID(uuid_struct)	COPY_UUID_128(uuid_struct,0x04,0x60,0x00,0x00,0x00,0x01, 0x11,0xe2, 0xac,0x36, 0x00,0x02,0xa5,0xd5,0xc5,0x1b)


uint16_t ResServHandle, Res1CharHandle, Res2CharHandle;
uint16_t CapServHandle, Cap1CharHandle, Cap2CharHandle, Cap3CharHandle, Cap4CharHandle;

/* UUIDS */
Service_UUID_t service_uuid;
Char_UUID_t char_uuid;
Char_Desc_Uuid_t char_desc_uuid;

extern uint16_t connection_handle;

  
/*******************************************************************************
* Function Name  : Add_Res_Service
* Description    : Add the 'Resistive' service.
* Input          : None
* Return         : Status.
*******************************************************************************/
tBleStatus Add_Res_Service(void)
{
  tBleStatus ret;
  uint8_t uuid[16];

  COPY_RES_SERVICE_UUID(uuid);
    
  Osal_MemCpy(&service_uuid.Service_UUID_128, uuid, 16);
  ret = aci_gatt_add_service(UUID_TYPE_128,  &service_uuid, PRIMARY_SERVICE, Services_Max_Attribute_Records[0], &ResServHandle);
  if (ret != BLE_STATUS_SUCCESS) goto fail;    

  COPY_RES1_CHAR_UUID(uuid);
  Osal_MemCpy(&char_uuid.Char_UUID_128, uuid, 16);
  // Characteristic length includes 2 bytes for time + 7 16-bit spaces for resistive values
  ret =  aci_gatt_add_char(ResServHandle, UUID_TYPE_128, &char_uuid, 16, CHAR_PROP_NOTIFY, ATTR_PERMISSION_NONE, 0,
                           16, 0, &Res1CharHandle);
  if (ret != BLE_STATUS_SUCCESS) goto fail;

  COPY_RES2_CHAR_UUID(uuid);
  Osal_MemCpy(&char_uuid.Char_UUID_128, uuid, 16);
  // Characteristic length includes 2 bytes for time + 8 16-bit spaces for resistive values
  ret =  aci_gatt_add_char(ResServHandle, UUID_TYPE_128, &char_uuid, 18, CHAR_PROP_NOTIFY, ATTR_PERMISSION_NONE, 0,
 						 16, 0, &Res2CharHandle);
  if (ret != BLE_STATUS_SUCCESS) goto fail;

  PRINTF("Service RES added. Handle 0x%04X, Res1 Charac handle: 0x%04X, Res2 Charac handle: 0x%04X\n",ResServHandle, Res1CharHandle, Res2CharHandle);
  return BLE_STATUS_SUCCESS; 

 fail:
  PRINTF("Error while adding RES service.\n");
  return BLE_STATUS_ERROR ;
    
}

/*******************************************************************************
* Function Name  : Add_Cap_Service
* Description    : Add the 'Capacitive' service.
* Input          : None
* Return         : Status.
*******************************************************************************/
tBleStatus Add_Cap_Service(void)
{
  tBleStatus ret;
  uint8_t uuid[16];

  COPY_CAP_SERVICE_UUID(uuid);

  Osal_MemCpy(&service_uuid.Service_UUID_128, uuid, 16);
  ret = aci_gatt_add_service(UUID_TYPE_128,  &service_uuid, PRIMARY_SERVICE, Services_Max_Attribute_Records[1], &CapServHandle);
  if (ret != BLE_STATUS_SUCCESS) goto fail;

  COPY_CAP1_CHAR_UUID(uuid);
  Osal_MemCpy(&char_uuid.Char_UUID_128, uuid, 16);
  // Characteristic length includes 2 bytes for time + 4 32-bit spaces for capacitive values
  ret =  aci_gatt_add_char(CapServHandle, UUID_TYPE_128, &char_uuid, 18, CHAR_PROP_NOTIFY, ATTR_PERMISSION_NONE, 0,
                           16, 0, &Cap1CharHandle);
  if (ret != BLE_STATUS_SUCCESS) goto fail;

  COPY_CAP2_CHAR_UUID(uuid);
  Osal_MemCpy(&char_uuid.Char_UUID_128, uuid, 16);
  // Characteristic length includes 2 bytes for time + 4 32-bit spaces for capacitive values
  ret =  aci_gatt_add_char(CapServHandle, UUID_TYPE_128, &char_uuid, 18, CHAR_PROP_NOTIFY, ATTR_PERMISSION_NONE, 0,
                           16, 0, &Cap2CharHandle);
  if (ret != BLE_STATUS_SUCCESS) goto fail;

  COPY_CAP3_CHAR_UUID(uuid);
  Osal_MemCpy(&char_uuid.Char_UUID_128, uuid, 16);
  // Characteristic length includes 2 bytes for time + 4 32-bit spaces for capacitive values
  ret =  aci_gatt_add_char(CapServHandle, UUID_TYPE_128, &char_uuid, 18, CHAR_PROP_NOTIFY, ATTR_PERMISSION_NONE, 0,
		  	  	  	  	  16, 0, &Cap3CharHandle);
  if (ret != BLE_STATUS_SUCCESS) goto fail;

  COPY_CAP4_CHAR_UUID(uuid);
  Osal_MemCpy(&char_uuid.Char_UUID_128, uuid, 16);
  // Characteristic length includes 2 bytes for time + 3 32-bit spaces for capacitive values
  ret =  aci_gatt_add_char(CapServHandle, UUID_TYPE_128, &char_uuid, 14, CHAR_PROP_NOTIFY, ATTR_PERMISSION_NONE, 0,
		  	  	  	  	  16, 0, &Cap4CharHandle);
  if (ret != BLE_STATUS_SUCCESS) goto fail;

  PRINTF("Service CAP added. Handle 0x%04X, Cap1 Charac handle: 0x%04X, Cap2 Charac handle: 0x%04X, Cap3 Charac handle: 0x%04X, Cap4 Charac handle: 0x%04X\n",CapServHandle, Cap1CharHandle, Cap2CharHandle, Cap3CharHandle, Cap4CharHandle);
  return BLE_STATUS_SUCCESS;

 fail:
  PRINTF("Error while adding CAP service.\n");
  return BLE_STATUS_ERROR ;

}

/*******************************************************************************
* Function Name  : ResCap_Update
* Description    : Update resistive & capacitive characteristic values
* Input          : uint16_t structure containing data values.
* Return         : Status.
*******************************************************************************/
tBleStatus ResCap_Update(uint8_t data[])
{
  tBleStatus ret;
  uint8_t Resistive[30];
  uint8_t Capacitive[60];
  uint8_t i=0;

  for(i=0;i<30;i++){
	  Resistive[i] = data[i];
  }
  for(i=0;i<60;i++){
	  Capacitive[i] = data[i+30];
  }

  ret = Res_Update(Resistive);
  if (ret != BLE_STATUS_SUCCESS) goto fail;

  ret = Cap_Update(Capacitive);
  if (ret != BLE_STATUS_SUCCESS) goto fail;

  return BLE_STATUS_SUCCESS;

  fail:
    PRINTF("Error while updating Resistive & capacitive characteristics: 0x%02X\n",ret) ;
    return BLE_STATUS_ERROR ;
}

/*******************************************************************************
* Function Name  : Res_Update
* Description    : Update resistive characteristic values
* Input          : uint16_t structure containing resistive values.
* Return         : Status.
*******************************************************************************/
tBleStatus Res_Update(uint8_t resistive[])
{
  tBleStatus ret;
  uint8_t Resistive1[14];
  uint8_t Resistive2[16];
  uint8_t i=0;

  for(i=0;i<14;i++){
	  Resistive1[i] = resistive[i];
  }
  for(i=0;i<16;i++){
	  Resistive2[i] = resistive[i+14];
  }

  ret = Res1_Update(Resistive1);
  if (ret != BLE_STATUS_SUCCESS) goto fail;

  ret = Res2_Update(Resistive2);
  if (ret != BLE_STATUS_SUCCESS) goto fail;

  return BLE_STATUS_SUCCESS;

  fail:
    PRINTF("Error while updating Resistive characteristics: 0x%02X\n",ret) ;
    return BLE_STATUS_ERROR ;
}

/*******************************************************************************
* Function Name  : Res1_Update
* Description    : Update resistive 1 characteristic value
* Input          : uint16_t structure containing resistive value.
* Return         : Status.
*******************************************************************************/
tBleStatus Res1_Update(uint8_t resistive[])
{  
  uint8_t buff[16];
  tBleStatus ret;
  uint8_t i = 0;

  HOST_TO_LE_16(buff,(BLUE_CTRL->CURRENT_TIME >> 8));
  for(i=0;i<7;i++){
	  buff[2+i*2] = resistive[2*i];
	  buff[3+i*2] = resistive[2*i+1];
  }

  ret = aci_gatt_update_char_value_ext(connection_handle, ResServHandle, Res1CharHandle, 1, 16, 0, 16, buff);
  if (ret != BLE_STATUS_SUCCESS){
    PRINTF("Error while updating Resistive 1 characteristic: 0x%02X\n",ret) ;
    return BLE_STATUS_ERROR ;
  }

  return BLE_STATUS_SUCCESS;
    
}

/*******************************************************************************
* Function Name  : Res2_Update
* Description    : Update resistive 2 characteristic value
* Input          : uint16_t structure containing resistive value.
* Return         : Status.
*******************************************************************************/
tBleStatus Res2_Update(uint8_t resistive[])
{
  uint8_t buff[18];
  tBleStatus ret;
  uint8_t i = 0;

  HOST_TO_LE_16(buff,(BLUE_CTRL->CURRENT_TIME >> 8));
  for(i=0;i<8;i++){
	  buff[2+i*2] = resistive[2*i];
	  buff[3+i*2] = resistive[2*i+1];
  }

  ret = aci_gatt_update_char_value_ext(connection_handle, ResServHandle, Res2CharHandle, 1, 18, 0, 18, buff);
  if (ret != BLE_STATUS_SUCCESS){
    PRINTF("Error while updating Resistive 2 characteristic: 0x%02X\n",ret) ;
    return BLE_STATUS_ERROR ;
  }

  return BLE_STATUS_SUCCESS;

}

/*******************************************************************************
* Function Name  : Cap_Update
* Description    : Update capacitive characteristic values
* Input          : uint16_t structure containing capacitive values.
* Return         : Status.
*******************************************************************************/
tBleStatus Cap_Update(uint8_t capacitive[])
{
  tBleStatus ret;
  uint8_t Capacitive1[16];
  uint8_t Capacitive2[16];
  uint8_t Capacitive3[16];
  uint8_t Capacitive4[12];
  uint8_t i=0;

  for(i=0;i<16;i++){
	  Capacitive1[i] = capacitive[i];
  }
  for(i=0;i<16;i++){
	  Capacitive2[i] = capacitive[i+16];
  }
  for(i=0;i<16;i++){
  	  Capacitive3[i] = capacitive[i+16*2];
  }
  for(i=0;i<12;i++){
  	  Capacitive4[i] = capacitive[i+16*3];
  }

  ret = Cap1_Update(Capacitive1);
  if (ret != BLE_STATUS_SUCCESS) goto fail;

  ret = Cap2_Update(Capacitive2);
  if (ret != BLE_STATUS_SUCCESS) goto fail;

  ret = Cap3_Update(Capacitive3);
  if (ret != BLE_STATUS_SUCCESS) goto fail;

  ret = Cap4_Update(Capacitive4);
  if (ret != BLE_STATUS_SUCCESS) goto fail;

  return BLE_STATUS_SUCCESS;

  fail:
    PRINTF("Error while updating Capacitive characteristics: 0x%02X\n",ret) ;
    return BLE_STATUS_ERROR ;
}

/*******************************************************************************
* Function Name  : Cap1_Update
* Description    : Update capacitive 1 characteristic value
* Input          : uint16_t structure containing capacitive value.
* Return         : Status.
*******************************************************************************/
tBleStatus Cap1_Update(uint8_t capacitive[])
{
  uint8_t buff[18];
  tBleStatus ret;
  uint8_t i = 0;

  HOST_TO_LE_16(buff,(BLUE_CTRL->CURRENT_TIME >> 8));
  for(i=0;i<16;i++){
	  buff[2+i] = capacitive[i];
  }

  ret = aci_gatt_update_char_value_ext(connection_handle, CapServHandle, Cap1CharHandle, 1, 18, 0, 18, buff);
  if (ret != BLE_STATUS_SUCCESS){
    PRINTF("Error while updating Capacitive 1 characteristic: 0x%02X\n",ret) ;
    return BLE_STATUS_ERROR ;
  }

  return BLE_STATUS_SUCCESS;

}

tBleStatus Cap2_Update(uint8_t capacitive[])
{
  uint8_t buff[18];
  tBleStatus ret;
  uint8_t i = 0;

  HOST_TO_LE_16(buff,(BLUE_CTRL->CURRENT_TIME >> 8));
  for(i=0;i<16;i++){
	  buff[2+i] = capacitive[i];
  }

  ret = aci_gatt_update_char_value_ext(connection_handle, CapServHandle, Cap2CharHandle, 1, 18, 0, 18, buff);
  if (ret != BLE_STATUS_SUCCESS){
    PRINTF("Error while updating Capacitive 2 characteristic: 0x%02X\n",ret) ;
    return BLE_STATUS_ERROR ;
  }

  return BLE_STATUS_SUCCESS;

}

tBleStatus Cap3_Update(uint8_t capacitive[])
{
  uint8_t buff[18];
  tBleStatus ret;
  uint8_t i = 0;

  HOST_TO_LE_16(buff,(BLUE_CTRL->CURRENT_TIME >> 8));
  for(i=0;i<16;i++){
	  buff[2+i] = capacitive[i];
  }

  ret = aci_gatt_update_char_value_ext(connection_handle, CapServHandle, Cap3CharHandle, 1, 18, 0, 18, buff);
  if (ret != BLE_STATUS_SUCCESS){
    PRINTF("Error while updating Capacitive 3 characteristic: 0x%02X\n",ret) ;
    return BLE_STATUS_ERROR ;
  }

  return BLE_STATUS_SUCCESS;

}

tBleStatus Cap4_Update(uint8_t capacitive[])
{
  uint8_t buff[14];
  tBleStatus ret;
  uint8_t i = 0;

  HOST_TO_LE_16(buff,(BLUE_CTRL->CURRENT_TIME >> 8));
  for(i=0;i<12;i++){
	  buff[2+i] = capacitive[i];
  }

  ret = aci_gatt_update_char_value_ext(connection_handle, CapServHandle, Cap4CharHandle, 1, 14, 0, 14, buff);
  if (ret != BLE_STATUS_SUCCESS){
    PRINTF("Error while updating Capacitive 4 characteristic: 0x%02X\n",ret) ;
    return BLE_STATUS_ERROR ;
  }

  return BLE_STATUS_SUCCESS;

}


/*******************************************************************************
* Function Name  : Read_Request_CB.
* Description    : Update the sensor value.
* Input          : Handle of the characteristic to update.
* Return         : None.
*******************************************************************************/
void Read_Request_CB(uint16_t handle)
{
  if(connection_handle !=0)
  {
    aci_gatt_allow_read(connection_handle);
  }
}

