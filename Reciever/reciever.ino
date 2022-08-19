#include <SPI.h>
#include "mirf.h"
#include "nRF24L01.h"
#include "MirfHardwareSpiDriver.h"
Nrf241 Mirf = Nrf241(10, 9);
int value[3];

void setup(){
    Serial.begin(9600);
    Mirf.spi = &MirfHardwareSpi;
    Mirf.init();
    Mirf.setRADDR((byte*)"Jack");
    Mirf.payload = sizeof(value);
    Mirf.channel = 76;
    Mirf.config();
    Serial.print("Reading")
}

void loop() {
    if (Mirf.isDataReady()) {
        Mirf.getData((byte*)value);
        Serial.print("Received: ");
        Serial.print(value[0]);
        Serial.print(", ");
        Serial.println(value[1]);
    }
}