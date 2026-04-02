/**
 * @file    SDK_EVAL_SPI.c
 * @author  AMS VMA RF application team
 * @version V1.0.0
 * @date    September 29, 2015
 * @brief   This file provides all the low level API to manage SPI interface for eval board.
 * @details
 *
 * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 *
 * THIS SOURCE CODE IS PROTECTED BY A LICENSE.
 * FOR MORE INFORMATION PLEASE CAREFULLY READ THE LICENSE AGREEMENT FILE LOCATED
 * IN THE ROOT DIRECTORY OF THIS FIRMWARE PACKAGE.
 *
 * <h2><center>&copy; COPYRIGHT 2015 STMicroelectronics</center></h2>
 */


/* Includes ------------------------------------------------------------------*/
#include "SDK_EVAL_SPI.h"


/** @addtogroup SDK_EVAL_BlueNRG1         SDK EVAL BlueNRG1
 * @{
 */


/** @addtogroup SDK_EVAL_SPI              SDK EVAL SPI
 * @{
 */

/** @defgroup SDK_EVAL_SPI_Private_TypesDefinitions       SDK EVAL SPI Private Types Definitions
 * @{
 */

/**
 * @}
 */


/** @defgroup SDK_EVAL_SPI_Private_Defines                SDK EVAL SPI Private Defines
 * @{
 */




/**
 * @brief  SPI IRQ mode defines
 */
#define SEND_START       0
#define SEND_READ_REG    1
#define SEND_WRITE_REG   2
#define SEND_WRITE_DATA  3

/**
 * @}
 */


/** @defgroup SDK_EVAL_SPI_Private_Variable               SDK EVAL SPI Private Variable
 * @{
 */

/**
 * @brief  SPI buffers used for DMA application
 */
volatile uint8_t spi_buffer_tx[SPI_BUFF_SIZE];
volatile uint8_t spi_buffer_rx[SPI_BUFF_SIZE];

/**
 * @brief  SPI flag set at end of transaction
 */
volatile FlagStatus spi_eot = SET;

static uint16_t byte_to_send = 0;
static uint8_t* spi_buffer_ptr;
static uint8_t buffer_idx = 0;
static uint8_t byte_to_send_max = 0;
static uint8_t register_addr = 0;
static uint8_t spi_irq_state = SEND_START;

/**
 * @}
 */

/** @defgroup SDK_EVAL_SPI_Private_Macros                 SDK EVAL SPI Private Macros
 * @{
 */

/**
 * @}
 */


/**
 * @defgroup SDK_EVAL_SPI_Private_FunctionPrototypes      SDK EVAL SPI Private Function Prototypes
 * @{
 */

/**
 * @}
 */


/**
 * @defgroup SDK_EVAL_SPI_Private_Functions               SDK EVAL SPI Private Functions
 * @{
 */

/**
 * @}
 */


/**
 * @defgroup SDK_EVAL_SPI_Public_Functions                SDK EVAL SPI Public Functions
 * @{
 */


/**
 * @brief  Configures SPI interface
 * @param  baudrate: SPI clock frequency
 * @retval ErrorStatus: error status @ref ErrorStatus
 *         This parameter can be: SUCCESS or ERROR.
 */
ErrorStatus SdkEvalSpiInit(uint32_t baudrate)
{
  SPI_InitType SPI_InitStructure;
  GPIO_InitType GPIO_InitStructure;
  
  /* Enable SPI and GPIO clocks */
  SysCtrl_PeripheralClockCmd(CLOCK_PERIPH_GPIO | CLOCK_PERIPH_SPI, ENABLE);   
  
  /* Configure SPI pins */
  GPIO_StructInit(&GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Pin = SDK_EVAL_SPI_PERIPH_OUT_PIN;
  GPIO_InitStructure.GPIO_Mode = SDK_EVAL_SPI_PERIPH_OUT_MODE;
  GPIO_InitStructure.GPIO_Pull = ENABLE;
  GPIO_InitStructure.GPIO_HighPwr = DISABLE;
  GPIO_Init(&GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = SDK_EVAL_SPI_PERIPH_IN_PIN;
  GPIO_InitStructure.GPIO_Mode = SDK_EVAL_SPI_PERIPH_IN_MODE;  
  GPIO_Init(&GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = SDK_EVAL_SPI_PERIPH_SCLK_PIN;
  GPIO_InitStructure.GPIO_Mode = SDK_EVAL_SPI_PERIPH_SCLK_MODE;
  GPIO_Init(&GPIO_InitStructure);  
  
  /* Configure CS pin */
  GPIO_InitStructure.GPIO_Pin = SDK_EVAL_SPI_PERIPH_SENSOR_PIN;
  GPIO_InitStructure.GPIO_Mode = SDK_EVAL_SPI_PERIPH_SENSOR_MODE;
  GPIO_Init(&GPIO_InitStructure);
  
  /* Configure IRQ pin */
  GPIO_InitStructure.GPIO_Pin = SDK_EVAL_IRQ_SENSOR_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Output;
  GPIO_Init(&GPIO_InitStructure);
  SDK_EVAL_SPI_IRQ_LOW();


  /* Configure SPI in master mode */
  SPI_StructInit(&SPI_InitStructure);
  SPI_InitStructure.SPI_Mode = SPI_Mode_Slave;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b ;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
  SPI_InitStructure.SPI_BaudRate = baudrate;
  SPI_Init(&SPI_InitStructure);
  
  /* Clear RX and TX FIFO */
  SPI_ClearTXFIFO();
  SPI_ClearRXFIFO();
  
  /* Enable SPI functionality */
  SPI_Cmd(ENABLE);
  
  return SUCCESS;
  
}


/**
 * @brief  SPI function to read data from master STM32
 * @param  pBuffer: buffer to retrieve data from a slave
 * @param  DataType: type of data read
 * @retval ErrorStatus: error status @ref ErrorStatus
 *         This parameter can be: SUCCESS or ERROR.
 */
ErrorStatus SdkEvalSpiRead(uint8_t* pBuffer, uint8_t* DataType)
{
  uint8_t NumByteToRead = 0;
  uint16_t timeout = 0;
  SPI_ClearTXFIFO();
  SPI_ClearRXFIFO();
  SDK_EVAL_SPI_IRQ_HIGH();
  
  /* Read type of data to receive */
  SPI_SendData(0x88);
  while((RESET == SPI_GetFlagStatus(SPI_FLAG_RNE)) && (timeout++ < SPI_TIMEOUT_MAX));
  if (timeout >= SPI_TIMEOUT_MAX) goto fail;
  *DataType = SPI_ReceiveData();

  // Read data type and accordingly read number of bytes
  	  // 0x00: No data to read, treated as default case
  	  // 0x01: Resistor data to read
  	  // 0x02: Capacitor data to read
  	  // 0x03: Res and Cap data to read
  switch (*DataType) {
  	  case 0x00:
    	NumByteToRead = 0;
    	break;
  	  case 0x01:
  		  NumByteToRead = 30;
  		  break;
  	  case 0x02:
  		  NumByteToRead = 60;
  		  break;
  	  case 0x03:
  		  NumByteToRead = 90;
  		  break;
  	  default:
  		  NumByteToRead = 0;
  		  goto fail;
  }

  timeout = 0;
  for(uint8_t i = 0; i< NumByteToRead; i++) {
	SPI_SendData(0xFF);
    while((RESET == SPI_GetFlagStatus(SPI_FLAG_RNE)) && (timeout++ < SPI_TIMEOUT_MAX));
    if(timeout >= SPI_TIMEOUT_MAX) goto fail;
    pBuffer[i] = SPI_ReceiveData();

  }
  
  timeout = 0;
  while ((SET == SPI_GetFlagStatus(SPI_FLAG_BSY)) && (timeout++ < SPI_TIMEOUT_MAX));
  if(timeout >= SPI_TIMEOUT_MAX) goto fail;
  
  SDK_EVAL_SPI_IRQ_LOW();

  return SUCCESS;

  fail:
  	  SDK_EVAL_SPI_IRQ_LOW();
  	  SPI_ClearTXFIFO();
  	  SPI_ClearRXFIFO();
  	  return ERROR;
}


/**
 * @brief  SPI function to write registers of a slave device
 * @param  pBuffer: buffer contains data to write
 * @param  RegisterAddr: register address
 * @param  NumByteToRead: number of byte to write
 * @retval ErrorStatus: error status @ref ErrorStatus
 *         This parameter can be: SUCCESS or ERROR.
 */
ErrorStatus SdkEvalSpiWrite(uint8_t* pBuffer, uint8_t RegisterAddr, uint8_t NumByteToWrite)
{
  /* Set communication mode */
  SPI_SetMasterCommunicationMode(SPI_TRANSMIT_MODE);

  SDK_EVAL_SPI_CS_LOW();

  /* Write command to be send send to TX FIFO */
  SPI_SendData(RegisterAddr);

  /* Write data to be send send to TX FIFO */
  for(uint8_t i=0;i<NumByteToWrite;i++)
    SPI_SendData(pBuffer[i]);

  /* Wait until data transfer is finished */
  while (SET == SPI_GetFlagStatus(SPI_FLAG_BSY));

  SDK_EVAL_SPI_CS_HIGH();
  return SUCCESS;

}



/**
 * @brief  Configures SPI interface and the SPI_TX/SPI_RX DMA channels
 * @param  baudrate: SPI clock frequency
 * @retval ErrorStatus: error status @ref ErrorStatus
 *         This parameter can be: SUCCESS or ERROR.
 */
ErrorStatus SdkEvalSpiDmaInit(uint32_t baudrate)
{
  SPI_InitType SPI_InitStructure;
  GPIO_InitType GPIO_InitStructure;
  DMA_InitType DMA_InitStructure;
  NVIC_InitType NVIC_InitStructure;

  /* Enable SPI and GPIO clocks */
  SysCtrl_PeripheralClockCmd(CLOCK_PERIPH_GPIO | CLOCK_PERIPH_SPI | CLOCK_PERIPH_DMA, ENABLE);

  /* Configure SPI pins */
  GPIO_StructInit(&GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Pin = SDK_EVAL_SPI_PERIPH_OUT_PIN | SDK_EVAL_SPI_PERIPH_SCLK_PIN | SDK_EVAL_SPI_PERIPH_IN_PIN;
  GPIO_InitStructure.GPIO_Mode = Serial0_Mode;
  GPIO_InitStructure.GPIO_Pull = ENABLE;
  GPIO_InitStructure.GPIO_HighPwr = DISABLE;
  GPIO_Init(&GPIO_InitStructure);

  /* Configure CS pin */
    GPIO_InitStructure.GPIO_Pin = SDK_EVAL_SPI_PERIPH_SENSOR_PIN;
    GPIO_InitStructure.GPIO_Mode = SDK_EVAL_SPI_PERIPH_SENSOR_MODE;
    GPIO_Init(&GPIO_InitStructure);

    /* Configure IRQ pin */
    GPIO_InitStructure.GPIO_Pin = SDK_EVAL_IRQ_SENSOR_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Output;
    GPIO_Init(&GPIO_InitStructure);
    SDK_EVAL_SPI_IRQ_LOW();

  /* Configure SPI in master mode */
  SPI_StructInit(&SPI_InitStructure);
  SPI_InitStructure.SPI_Mode = SPI_Mode_Slave;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b ;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
  SPI_InitStructure.SPI_BaudRate = baudrate;
  SPI_Init(&SPI_InitStructure);

  /* Clear RX and TX FIFO */
  SPI_ClearTXFIFO();
  SPI_ClearRXFIFO();

  /* Configure DMA SPI TX channel */
  DMA_InitStructure.DMA_PeripheralBaseAddr = SPI_DR_BASE_ADDR;
  DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)spi_buffer_tx;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
  DMA_InitStructure.DMA_BufferSize = (uint32_t)SPI_BUFF_SIZE;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
  DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
  DMA_Init(DMA_CH_SPI_TX, &DMA_InitStructure);

  /* Configure DMA SPI RX channel */
  DMA_InitStructure.DMA_PeripheralBaseAddr = SPI_DR_BASE_ADDR;
  DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)spi_buffer_rx;
  DMA_InitStructure.DMA_BufferSize = (uint32_t)SPI_BUFF_SIZE;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  DMA_Init(DMA_CH_SPI_RX, &DMA_InitStructure);

  /* Enable DMA_CH_SPI_RX Transfer Complete interrupt */
  DMA_FlagConfig(DMA_CH_SPI_RX, DMA_FLAG_TC, ENABLE);

  /* Enable SPI_TX/SPI_RX DMA requests */
  SPI_DMACmd(SPI_DMAReq_Tx | SPI_DMAReq_Rx, ENABLE);

  /* Enable the DMA Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = DMA_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = MED_PRIORITY;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  /* Enable SPI functionality */
  SPI_Cmd(ENABLE);

  return SUCCESS;
}


/**
 * @brief  SPI DMA function to read registers from a slave device
 * @param  pBuffer: buffer to retrieve data from a slave
 * @param  RegisterAddr: register address
 * @param  NumByteToRead: number of byte to read
 * @retval ErrorStatus: error status @ref ErrorStatus
 *         This parameter can be: SUCCESS or ERROR.
 */
ErrorStatus SdkEvalSpiDmaRead(uint8_t* pBuffer, uint8_t* DataType)
{
  spi_buffer_tx[0] = 0x88;
  for(uint8_t i=0;i<SPI_BUFF_SIZE-1;i++) {
    spi_buffer_tx[1+i] = 0xFF;
  }
  while(spi_eot==RESET);
  spi_eot = RESET;

  SDK_EVAL_SPI_IRQ_HIGH();

  /* Reset DMA_CH_UART_TX remaining bytes register */
  DMA_CH_SPI_TX->CNDTR = 91;
  DMA_CH_SPI_RX->CNDTR = 91;

  /* DMA_CH_UART_TX enable */
  DMA_CH_SPI_RX->CCR_b.EN = SET;
  DMA_CH_SPI_TX->CCR_b.EN = SET;

  while(spi_eot==RESET);

  *DataType = spi_buffer_rx[0];
  uint8_t numByte = 0;
  switch (*DataType) {
	case 0x01: numByte = 30; break;
	case 0x02: numByte = 60; break;
	case 0x03: numByte = 90; break;
	default: numByte = 0; break;
  }
  for(uint8_t i=0;i<numByte;i++) {
    pBuffer[i] = spi_buffer_rx[1+i];
  }

  return SUCCESS;
}


/**
 * @brief  SPI DMA function to write registers of a slave device
 * @param  pBuffer: buffer contains data to write
 * @param  RegisterAddr: register address
 * @param  NumByteToRead: number of byte to write
 * @retval ErrorStatus: error status @ref ErrorStatus
 *         This parameter can be: SUCCESS or ERROR.
 */
ErrorStatus SdkEvalSpiDmaWrite( uint8_t* pBuffer, uint8_t RegisterAddr, uint8_t NumByteToWrite )
{
  /** Set communication mode */
  SPI_SetMasterCommunicationMode(SPI_FULL_DUPLEX_MODE);

  spi_buffer_tx[0] = RegisterAddr;
  for(uint8_t i=0;i<NumByteToWrite;i++) {
    spi_buffer_tx[1+i] = pBuffer[i];
  }
  while(spi_eot==RESET);
  spi_eot = RESET;

  SDK_EVAL_SPI_CS_LOW();

  /* Reset DMA_CH_UART_TX remaining bytes register */
  DMA_CH_SPI_TX->CNDTR = NumByteToWrite+1;
  DMA_CH_SPI_RX->CNDTR = NumByteToWrite+1;

  /* DMA_CH_UART_TX enable */
  DMA_CH_SPI_RX->CCR_b.EN = SET;
  DMA_CH_SPI_TX->CCR_b.EN = SET;

  return SUCCESS;
}


/**
 * @brief  SPI DMA ISR callback function
 * @param  None
 * @retval None
 */
void DmaSpiHandlerCallback(void)
{
  /* Check DMA_CH_SPI_RX_IT_TC */
  if(DMA_GetFlagStatus(DMA_CH_SPI_RX_IT_TC)) {

    /* Clear pending bit */
    DMA_ClearFlag(DMA_CH_SPI_RX_IT_TC);

    /* DMA_SPI_TX/RX disable */
    DMA_CH_SPI_TX->CCR_b.EN = RESET;
    DMA_CH_SPI_RX->CCR_b.EN = RESET;

    /* Put the CS pin high */
    SDK_EVAL_SPI_IRQ_LOW();

    /* Set the spi_eot flag */
    spi_eot = SET;
  }

}



/**
 * @brief  Configures SPI interface and the SPI_TX/SPI_RX IRQ sources
 * @param  baudrate: SPI clock frequency
 * @retval ErrorStatus: error status @ref ErrorStatus
 *         This parameter can be: SUCCESS or ERROR.
 */
ErrorStatus SdkEvalSpiIrqInit(uint32_t baudrate)
{
  SPI_InitType SPI_InitStructure;
  GPIO_InitType GPIO_InitStructure;
  NVIC_InitType NVIC_InitStructure;

  /* Enable SPI and GPIO clocks */
  SysCtrl_PeripheralClockCmd(CLOCK_PERIPH_GPIO | CLOCK_PERIPH_SPI, ENABLE);

  /* Configure SPI pins */
  GPIO_StructInit(&GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Pin = SDK_EVAL_SPI_PERIPH_OUT_PIN | SDK_EVAL_SPI_PERIPH_SCLK_PIN | SDK_EVAL_SPI_PERIPH_IN_PIN;
  GPIO_InitStructure.GPIO_Mode = Serial0_Mode;
  GPIO_InitStructure.GPIO_Pull = ENABLE;
  GPIO_InitStructure.GPIO_HighPwr = DISABLE;
  GPIO_Init(&GPIO_InitStructure);

  /* Configure CS pin */
  GPIO_InitStructure.GPIO_Pin = SDK_EVAL_SPI_PERIPH_SENSOR_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Output;
  GPIO_Init(&GPIO_InitStructure);
  SDK_EVAL_SPI_CS_HIGH();

  /* Configure SPI in master mode */
  SPI_StructInit(&SPI_InitStructure);
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b ;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
  SPI_InitStructure.SPI_BaudRate = baudrate;
  SPI_Init(&SPI_InitStructure);

  /* Set communication mode */
  SPI_SetMasterCommunicationMode(SPI_FULL_DUPLEX_MODE);

  /* Clear RX and TX FIFO */
  SPI_ClearTXFIFO();
  SPI_ClearRXFIFO();

  /* Configure the level of FIFO for interrupt */
  SPI_TxFifoInterruptLevelConfig(SPI_FIFO_LEV_1);
  SPI_RxFifoInterruptLevelConfig(SPI_FIFO_LEV_1);

  /* Enable the DMA Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = SPI_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = LOW_PRIORITY;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  /* Enable SPI functionality */
  SPI_Cmd(ENABLE);

  return SUCCESS;
}



/**
 * @brief  SPI IRQ function to read registers from a slave device
 * @param  pBuffer: buffer to retrieve data from a slave
 * @param  RegisterAddr: register address
 * @param  NumByteToRead: number of byte to read
 * @retval ErrorStatus: error status @ref ErrorStatus
 *         This parameter can be: SUCCESS or ERROR.
 */
ErrorStatus SdkEvalSpiIrqRead( uint8_t* pBuffer, uint8_t RegisterAddr, uint8_t NumByteToRead )
{
  /** Set communication mode */
  SPI_SetMasterCommunicationMode(SPI_FULL_DUPLEX_MODE);

  byte_to_send = NumByteToRead;
  byte_to_send_max = NumByteToRead;
  register_addr  = RegisterAddr;
  spi_buffer_ptr = pBuffer;
  buffer_idx = 0;
  spi_irq_state = SEND_READ_REG;
  spi_eot = RESET;

  SDK_EVAL_SPI_CS_LOW();
  SPI_ITConfig(SPI_IT_TX | SPI_IT_RX, ENABLE);

  while(spi_eot == RESET);

  SPI_ITConfig(SPI_IT_TX | SPI_IT_RX, DISABLE);
  SDK_EVAL_SPI_CS_HIGH();

  return SUCCESS;
}


/**
 * @brief  SPI IRQ function to write registers of a slave device
 * @param  pBuffer: buffer contains data to write
 * @param  RegisterAddr: register address
 * @param  NumByteToRead: number of byte to write
 * @retval ErrorStatus: error status @ref ErrorStatus
 *         This parameter can be: SUCCESS or ERROR.
 */
ErrorStatus SdkEvalSpiIrqWrite( uint8_t* pBuffer, uint8_t RegisterAddr, uint8_t NumByteToWrite )
{
  /* Set communication mode */
  SPI_SetMasterCommunicationMode(SPI_TRANSMIT_MODE);

  byte_to_send = NumByteToWrite;
  byte_to_send_max = NumByteToWrite;
  register_addr  = RegisterAddr;
  spi_buffer_ptr = pBuffer;
  buffer_idx = 0;
  spi_irq_state = SEND_WRITE_REG;
  spi_eot = RESET;

  SDK_EVAL_SPI_CS_LOW();
  SPI_ITConfig(SPI_IT_TX, ENABLE);

  while(spi_eot == RESET);

  SPI_ITConfig(SPI_IT_TX, DISABLE);
  SDK_EVAL_SPI_CS_HIGH();
  return SUCCESS;
}


/**
 * @brief  SPI IRQ ISR callback function
 * @param  None
 * @retval None
 */
void IrqSpiHandlerCallback(void)
{
  /* Check if SPI RX interrupt event occured */
  if(SPI_GetITStatus(SPI_IT_RX) == SET) {

    if(buffer_idx==0) { /* First reception is discarded, dummy data from sensor */
      SPI_ReceiveData();
    }
    else {
      spi_buffer_ptr[buffer_idx-1] = SPI_ReceiveData();
    }

    /* When all the bytes are received, the flag is set */
    if(byte_to_send_max == buffer_idx)
      spi_eot = SET;

    /* Increase the buffer index */
    buffer_idx++;
  }

  /* Check if SPI RX interrupt event occured */
  if(SPI_GetITStatus(SPI_IT_TX) == SET) {

    if(byte_to_send>0) {
      if(spi_irq_state == SEND_READ_REG) {
        spi_irq_state = SEND_START;

        /* Send the header byte for read operation from register_addr */
        SPI_SendData(0x80 | register_addr);
      }
      else if(spi_irq_state == SEND_WRITE_REG) {
        spi_irq_state = SEND_WRITE_DATA;

        /* Send the header byte for write operation from register_addr */
        SPI_SendData(register_addr);
      }
      else if(spi_irq_state == SEND_WRITE_DATA){

        /* Decrease the bytes to send */
        byte_to_send--;

        /* Send data to write */
        SPI_SendData(spi_buffer_ptr[buffer_idx]);

        /* Increase the buffer index */
        buffer_idx++;
      }
      else {
        /* Decrease the bytes to send */
        byte_to_send--;

        /* Send dummy data */
        SPI_SendData(0xFF);
      }
    }
    else {
      SPI_ITConfig(SPI_IT_TX , DISABLE);
      if(spi_irq_state == SEND_WRITE_DATA)
        spi_eot = SET;
    }

  }

}


/**
 * @}
 */


/**
 * @}
 */

/**
 * @}
 */



/******************* (C) COPYRIGHT 2015 STMicroelectronics *****END OF FILE****/
