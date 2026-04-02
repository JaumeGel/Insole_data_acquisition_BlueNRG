
#ifndef _GATT_DB_H_
#define _GATT_DB_H_

#include "STM32Sensor.h"

/** 
 * @brief Number of application services
 */
#define NUMBER_OF_APPLICATION_SERVICES (2)

tBleStatus Add_Res_Service(void);
tBleStatus Add_Cap_Service(void);
void Read_Request_CB(uint16_t handle);
tBleStatus ResCap_Update(uint8_t data[]);
tBleStatus Res_Update(uint8_t resistive[]);
tBleStatus Res1_Update(uint8_t resistive[]);
tBleStatus Res2_Update(uint8_t resistive[]);
tBleStatus Cap_Update(uint8_t capacitive[]);
tBleStatus Cap1_Update(uint8_t capacitive[]);
tBleStatus Cap2_Update(uint8_t capacitive[]);
tBleStatus Cap3_Update(uint8_t capacitive[]);
tBleStatus Cap4_Update(uint8_t capacitive[]);

extern uint8_t Services_Max_Attribute_Records[];
#endif /* _GATT_DB_H_ */
