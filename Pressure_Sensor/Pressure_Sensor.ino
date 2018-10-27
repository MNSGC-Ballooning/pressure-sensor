//Code for the M4520 pressure and temperature sensor
//created by Simon Peterson 22.09.18
#include <SPI.h>

unsigned int receiveddata;
unsigned int secondPart;
void setup() {
  Serial.begin(57600);
  SPI.begin();
  SPI.beginTransaction(SPISettings(50000, MSBFIRST, SPI_MODE0));
  Serial.println("finished setup");
  pinMode(7, OUTPUT);
}

void loop() {
  digitalWrite(7, LOW);
  receiveddata = SPI.transfer16(0);
  secondPart = SPI.transfer16(0);
  delay(100);
  Serial.println(String(receiveddata));
  Serial.println(secondPart);
  digitalWrite(7,HIGH);
  delay(300);
  
}
