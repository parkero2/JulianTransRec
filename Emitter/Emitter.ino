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
    Mirf.setRADDR((byte*)"Julia");
    Mirf.payload = sizeof(value);
    Mirf.channel = 76;
    Mirf.config();
}

void loop(){
    Mirf.setTADDR((byte*)"Jack");
    value[0], value[1] = 12, 56;
    Mirf.send((byte*)value);
    while (Mirf.isSending())
    {
        delay(10)
    }
}