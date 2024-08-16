#include "mbed.h"
#include "non_blocking_delay.h"
#include "MFRC522.h"
//#include <stdio.h>
//#include <stdbool.h>
//#include <string.h> 
#include "arm_book_lib.h"
#include "ble_com.h"
#include "my_string.h"
//=====[#include guards - begin]===============================================
#ifndef _RFID_H_
#define _RFID_H_
//==================[Libraries]=================================================

#define SYSTEM_TIME_INCREMENT_MS 10
//=====[Declaration of public data types]======================================

typedef enum{
      RFID_WAIT,
      RFID_NEW_TAG,
} rfidState_t;

//static int cantidad_mascotas = 0;
extern char* uid;

void evento();

//=====[Declarations (prototypes) of public functions]=========================

void rfidUpdate();
void rfidInit();
char* rfidGetUid();
void regDatosUpdate();

//=====[#include guards - end]=================================================
#endif // _RFID_H_