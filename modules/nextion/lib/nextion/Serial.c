#include "Serial.h"
#include "Utilities.h"
#include "stm32h7xx_hal.h"


UART_HandleTypeDef huart; // UART1 Handle

// Initialize UART with specified baud rate
void Serial_Init(long baudrate) {
    huart.Instance = UART5;
    huart.Init.BaudRate = baudrate;
    huart.Init.WordLength = UART_WORDLENGTH_8B;
    huart.Init.StopBits = UART_STOPBITS_1;
    huart.Init.Parity = UART_PARITY_NONE;
    huart.Init.Mode = UART_MODE_TX_RX;
    huart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart.Init.OverSampling = UART_OVERSAMPLING_16;

    if (HAL_UART_Init(&huart) != HAL_OK) {
        // Initialization Error
        printf("error while init");
    }
}

// Write a single byte over UART
unsigned char Serial_Write(unsigned char c) {
    if (HAL_UART_Transmit(&huart, &c, 1, HAL_MAX_DELAY) == HAL_OK) {
        return 1; // Success
    }
    return 0; // Error
}

// Read a single byte from UART
unsigned char Serial_Read() {
    unsigned char c;
    if (HAL_UART_Receive(&huart, &c, 1, HAL_MAX_DELAY) == HAL_OK) {
        return c;
    }
    return 0; // Error or no data
}

// Check if data is available to read
unsigned char Serial_Available() {
    return __HAL_UART_GET_FLAG(&huart, UART_FLAG_RXNE) ? 1 : 0;
}

// Read multiple bytes from UART
unsigned char Serial_ReadBytes(char *buf, unsigned char len) {
    if (HAL_UART_Receive(&huart, (uint8_t *)buf, len, HAL_MAX_DELAY) == HAL_OK) {
        return len;
    }
    return 0; // Error
}

// Print a string over UART
void Serial_Print(unsigned char *txt) {
    while (*txt) {
        Serial_Write(*txt++);
    }
}

void delay_ms(uint32_t ms) {
    HAL_Delay(ms);
}
