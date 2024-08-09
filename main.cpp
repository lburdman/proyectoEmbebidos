#include "arm_book_lib.h"
#include "mbed.h"
#include "system.h"

int main() {
    SystemInit();
    while(true) {
        SystemUpdate();
    }
}



/*PRUEBA RFID
#include "mbed.h"
#include "MFRC522.h"

// Definición de los pines
#define PIN_RFID_MOSI PA_7
#define PIN_RFID_MISO PA_6
#define PIN_RFID_SCLK PA_5
#define PIN_RFID_CS   PE_3
#define PIN_RFID_RESET PG_1

// Configuración del puerto serial para depuración
static BufferedSerial pc(USBTX, USBRX, 115200);

// Crear el objeto MFRC522 con los pines definidos
static MFRC522 rfid(PIN_RFID_MOSI, PIN_RFID_MISO, PIN_RFID_SCLK, PIN_RFID_CS, PIN_RFID_RESET);

void print_to_console(const char* message) {
    pc.write(message, strlen(message));
}

int main() {
    // Configurar el formato del puerto serial
    pc.set_format(8, BufferedSerial::None, 1);
    // Configurar la velocidad del puerto serial
    pc.set_baud(115200);

    // Imprimir mensaje de inicio
    print_to_console("Iniciando lector RFID\n");

    // Inicializar el lector RFID
    rfid.PCD_Init();

    // Imprimir mensaje de espera una vez
    print_to_console("Esperando para leer\n");

    while (true) {
        // Comprueba si hay una nueva tarjeta presente
        if (rfid.PICC_IsNewCardPresent()) {
            // Selecciona una de las tarjetas
            if (rfid.PICC_ReadCardSerial()) {
                // Imprime el UID de la tarjeta
                print_to_console("Card UID: ");
                for (uint8_t i = 0; i < rfid.uid.size; i++) {
                    char aux[10];
                    sprintf(aux, " %02X", rfid.uid.uidByte[i]);
                    print_to_console(aux);
                }
                print_to_console("\n\r");

                // Imprime el tipo de tarjeta
                uint8_t piccType = rfid.PICC_GetType(rfid.uid.sak);
                char aux[100];
                sprintf(aux, "PICC Type: %s \n\r", rfid.PICC_GetTypeName(piccType));
                print_to_console(aux);
            }
        }
        ThisThread::sleep_for(500ms); // Esperar 500 ms antes de volver a verificar
    }
}*/