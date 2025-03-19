#ifndef SERIAL_H
#define SERIAL_H
#include <stdint.h>

/*************************************************************************
* MACROS
*************************************************************************/
#define RX_BUFFER_SIZE 64
#define TX_BUFFER_SIZE 64
#define RX_Flush() _rx_buffer_head=0;_rx_buffer_tail=0
#define TX_Flush() _tx_buffer_head=0;_tx_buffer_tail=0
extern unsigned char rxBuff[64];
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