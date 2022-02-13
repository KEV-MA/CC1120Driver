#include <SPI.h>
#include "arduino_unit_tests.h"
#include "cc1120_spi.h"
#include "cc1120_unit_tests.h"
#include "arduino_unit_tests.h"

void setup() {
    Serial.begin(9600);

    pinMode(CS, OUTPUT);
    digitalWrite(CS, HIGH);
    SPI.begin();
    delay(1000);

    Serial.println("Starting unit tests...");
    checkSPIRead();
}

void loop() {

}
