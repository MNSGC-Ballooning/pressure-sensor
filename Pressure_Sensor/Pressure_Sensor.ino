//Code for the M4520 pressure and temperature sensor
//created by Simon Peterson 22.09.18
#include <SPI.h>

unsigned int receiveddata;
unsigned int secondPart;
float pressure;
float temp;
unsigned int mask = 0x3fff;
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
  secondPart = secondPart >> 5;
  receiveddata &= mask;
  temp = ((float)secondPart*200/2047) - 50;
  pressure = ((float)receiveddata/(float)mask)*15;
  Serial.println(pressure);
  Serial.println(temp);
  digitalWrite(7,HIGH);
  delay(300);
  
}
