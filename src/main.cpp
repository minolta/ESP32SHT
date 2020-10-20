#include <Arduino.h>
#include <Wire.h>
#include "SHTSensor.h"

SHTSensor sht;
void setup() {
  // put your setup code here, to run once:

  Wire.begin();
  Serial.begin(115200);
  delay(1000); // let serial console settle

  if (sht.init()) {
      Serial.print("init(): success\n");
  } else {
      Serial.print("init(): failed\n");
  }
  sht.setAccuracy(SHTSensor::SHT_ACCURACY_HIGH); // only supported by SHT3x

}

void loop() {
  // put your main code here, to run repeatedly:

  if (sht.readSample()) {
      Serial.print("SHT:\n");
      Serial.print("  RH: ");
      Serial.print(sht.getHumidity(), 2);
      Serial.print("\n");
      Serial.print("  T:  ");
      Serial.print(sht.getTemperature(), 2);
      Serial.print("\n");
  } else {
      Serial.print("Error in readSample()\n");
  }

  delay(1000);
}