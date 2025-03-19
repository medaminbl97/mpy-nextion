#ifndef SERIAL_H
#define SERIAL_H
#include <stdint.h>
#include "utils/usart.h"
#include "utils/ringbuffer.h"
/*************************************************************************
* MACROS
*************************************************************************/
#define RX_BUFFER_SIZE 64
#define TX_BUFFER_SIZE 64
#define COMMANDE_MAX_RXCOMCHANNEL             (1U)
#define RX_Flush() _rx_buffer_head=0;_rx_buffer_tail=0
#define TX_Flush() _tx_buffer_head=0;_tx_buffer_tail=0
extern unsigned char rxBuff[1];
extern ring_buffer_t RxRingBuff[COMMANDE_MAX_RXCOMCHANNEL];

/*************************************************************************
* FUNCTIONS
*************************************************************************/
void Serial_Init(long baudrate);
unsigned char Serial_Write(unsigned char c);
unsigned char Serial_Read();
unsigned char Serial_Available();
unsigned char Serial_ReadBytes(char *buf, unsigned char len);
void Serial_Print(unsigned char *txt);
void delay_ms(uint32_t ms);

#endif