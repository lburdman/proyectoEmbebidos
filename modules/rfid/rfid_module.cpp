#include "rfid_module.h"

//=====[Declaration of private defines]========================================
#define MAX_LENGTH_UID 8

#define PIN_RFID_MOSI PA_7
#define PIN_RFID_MISO PA_6
#define PIN_RFID_SCLK PA_5
#define PIN_RFID_CS   PE_3
#define PIN_RFID_RESET PG_1

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalOut LedBlue(LED2);


//=====[Declaration and initialization of private global variables]============
MFRC522 rfid(PIN_RFID_MOSI, PIN_RFID_MISO, PIN_RFID_SCLK, PIN_RFID_CS, PIN_RFID_RESET);
nonBlockingDelay_t rfid_delay;
rfidState_t rfidState = RFID_WAIT;
bool vaccinated = false;
//bool SeDetectaMascota = false;

char buffer[MAX_LENGTH_UID + 1] = {'\0'};
char* uid = NULL;
//=====[Declarations (prototypes) of private functions]========================


//=====[Implementations of public functions]===================================


void rfidInit() {
    tickInit();
    rfid.PCD_Init();
}

void rfidUpdate(){
    switch (rfidState) {
        case RFID_WAIT:
            if (rfid.PICC_IsNewCardPresent()) {
                rfidState = RFID_NEW_TAG;
            }
            break;
        case RFID_NEW_TAG:
            if (!rfid.PICC_ReadCardSerial()) {
                break; 
            }
            for (uint8_t i = 0; i < rfid.uid.size; i++) {
                sprintf(buffer + i * 2, "%02X", rfid.uid.uidByte[i]);
            }
            uid = rfidGetUid();
            //SeDetectaMascota = true;
            break;
    }
}

void regDatosUpdate() {  
  /*HayEvento = false;    
  if (SeDetectaMascota && !Masc) {  
        Masc = true;
        LedBlue = 1;
        primer_valor = gramosPesados();
    } else if (!SeDetectaMascota && Masc) {
        LedBlue = 0;
        Masc = false;
        segundo_valor = gramosPesados();
        IndiceActual = detectarMascota(uid);
    }
    rfidEstado = RFID_WAIT;
    */
    if (rfidState == RFID_NEW_TAG) {

    }

}

char* rfidGetUid() {
    char* aux = NULL;
    if (rfidState != RFID_NEW_TAG) {
        char* aux = strndup_(buffer,10);
        buffer[0]={'\0'};
    } 
    return aux;
}
//=====[Implementations of private functions]==================================

