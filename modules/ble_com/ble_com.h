#include "mbed.h"
#include <string.h>
#include "arm_book_lib.h"

#ifndef _BLE_COM_H_
#define _BLE_COM_H_

//#define BUFFER_RX_SIZE 512
//#define BUFFER_TX_SIZE 512

/*typedef enum{
    COM_IDLE,
    TX_SEND_DATA,
    RX_BUFFERED,
    RX_READ_COMPLETE,
} bleComStatus_t;*/

//extern bool DataRecibida;

void testBLE();
char bleCharRead();
void bleStringWrite(char* str);
void SerialComStringRead(char* str, int strLength);

void SerialComUpdate();



#endif