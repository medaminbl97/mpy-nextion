#include "Serial.h"
#include "utils/Utilities.h"


unsigned char rxBuff[1];
#if 0
char rxHead, rxTail;
#endif
ring_buffer_t RxRingBuff[COMMANDE_MAX_RXCOMCHANNEL];


/**
  * @brief  Rx Transfer completed callback
  * @param  UartHandle: UART handle
  * @retval None
  */
#if 0
 volatile uint32_t RxCounter = 0 ;
#endif

void UART4_IRQHandler(void)
{
  /* USER CODE BEGIN UART4_IRQn 0 */

  /* USER CODE END UART4_IRQn 0 */
  HAL_UART_IRQHandler(&huart4);
  /* USER CODE BEGIN UART4_IRQn 1 */

  /* USER CODE END UART4_IRQn 1 */
}

 void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle)
 {
     if(UartHandle == &huart4)
     {      
        printf("Got a char : %c!\n",rxBuff[0]);
    	 ring_buffer_queue(&RxRingBuff[0],rxBuff[0]); /*Add Received Data To buffer*/
        // printf("got a char !\n");
#if 0
         RxCounter++;
         rxBuff[rxHead++] = (unsigned char)(huart4.Instance->RDR & 0xFF); // read the received data
         if (rxHead == sizeof(rxBuff))
         {
             rxHead = 0;
         }
#endif
     }
     HAL_UART_Receive_IT(&huart4, (uint8_t *)rxBuff, 1); // start the interrupt
 }


void Serial_Init(long baudrate)
{
	baudrate = baudrate;
    MX_GPIO_Init();
	MX_UART4_Init();
    // HAL_NVIC_SetPriority(UART4_IRQn, 0, 0);
    // HAL_NVIC_EnableIRQ(UART4_IRQn);
    HAL_UART_Receive_IT(&huart4, (uint8_t *)rxBuff, 1); // start the interrupt
}

unsigned char Serial_Write(unsigned char c)
{
	HAL_StatusTypeDef retval;
	retval =HAL_UART_Transmit(&huart4, &c, 1 , HAL_MAX_DELAY);

	if( HAL_OK == retval)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

unsigned char Serial_Read()
{
	unsigned char c;
	if(0 ==  ring_buffer_dequeue(&RxRingBuff[0], &c))
	{

		c = -1;
	}
	else
	{
		//do nothing
	}
#if 0
    if (rxTail < rxHead)
    {
        c = rxBuff[rxTail++];
        if (rxTail == rxHead)
        {
            rxHead = 0;
            rxTail = 0;
        }
    }
    else
    {
        rxHead = 0;
        rxTail = 0;
        c = -1;
    }
#endif
    return c;
}

unsigned char Serial_Available()
{
	return ring_buffer_num_items(&RxRingBuff[0]);
#if 0
	return rxHead - rxTail;
#endif
}

unsigned char Serial_ReadBytes(char *buf, unsigned char len)
{
	return ring_buffer_dequeue_arr(&RxRingBuff[0],buf, len); /*Add Received Data To buffer*/
#if 0
    unsigned char cnt = 0;
    if (len < rxHead - rxTail)
    {
        ArrayCopy(buf, &rxBuff[rxTail], len);
        rxTail += len;
        cnt = len;
    }
    else if (len == rxHead - rxTail)
    {
        ArrayCopy(buf, &rxBuff[rxTail], len);
        rxTail = 0;
        rxHead = 0;
        cnt = len;
    }
    else
    {
        ArrayCopy(buf, &rxBuff[rxTail], rxHead - rxTail);
        cnt = rxHead - rxTail;
        rxTail = 0;
        rxHead = 0;
    }
    return cnt;
#endif
}

void Serial_Print(unsigned char *txt)
{
    HAL_StatusTypeDef retval;
    short i = strlen((char *)txt);
    retval = HAL_UART_Transmit(&huart4, txt, i, HAL_MAX_DELAY);
}


void delay_ms(uint32_t ms) {
    HAL_Delay(ms);
}