#include "ble_com.h"
#include "my_string.h"

#define BLE_COM_BAUDRATE 9600

#define PIN_BLE_TX PD_6
#define PIN_BLE_RX PD_5
#define PIN_BLE_STATE PD_4

UnbufferedSerial bleCom(PIN_BLE_TX, PIN_BLE_RX, BLE_COM_BAUDRATE);

void bleComStringWrite(char* str) {
    bleCom.write(str, strlen_(str));
}

void SerialComStringRead(char* str, int strLength) {
    int strIndex;
    for (strIndex = 0; strIndex < strLength; strIndex++) {
        bleCom.read(&str[strIndex], 1);
        bleCom.write(&str[strIndex], 1);
    }
    str[strLength]='\0';
}

char bleComCharRead() {
    char receivedChar = '\0';
    if(bleCom.readable()) {
        bleCom.read(&receivedChar, 1);
    }
    return receivedChar;
}



