#include "ble_com.h"
#include "my_string.h"

#define BLE_COM_BAUDRATE 9600

#define PIN_BLE_TX PD_6
#define PIN_BLE_RX PD_5
#define PIN_BLE_STATE PD_4

UnbufferedSerial ble(PIN_BLE_TX, PIN_BLE_RX, BLE_COM_BAUDRATE);

void testBLE() {
    char message[] = "BLE funciona\n";
    bleStringWrite(message);
}

void bleStringWrite(char* str) {
    ble.write(str, strlen_(str));
}

void SerialComStringRead(char* str, int strLength) {
    int strIndex;
    for (strIndex = 0; strIndex < strLength; strIndex++) {
        ble.read(&str[strIndex], 1);
        ble.write(&str[strIndex], 1);
    }
    str[strLength]='\0';
}

char bleCharRead() {
    char receivedChar = '\0';
    if(ble.readable()) {
        ble.read(&receivedChar, 1);
    }
    return receivedChar;
}

void SerialComUpdate() {
    char receivedChar = bleCharRead();
    if (receivedChar != '\0') {
        switch (receivedChar) {
            case 'r': 
                //bleStringWrite();
                break;    
            case 'l': 
                //DataRecibida = true;
                break;
            default: 
                break;
        } 
    }
}


