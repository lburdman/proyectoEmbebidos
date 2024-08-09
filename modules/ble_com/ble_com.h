#include "mbed.h"
#include <string.h>
#include "arm_book_lib.h"

#ifndef _BLE_COM_H_
#define _BLE_COM_H_

char bleComCharRead();
void bleComStringWrite(char* str);
void SerialComStringRead(char* str, int strLength);


#endif