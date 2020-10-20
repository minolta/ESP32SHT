#ifndef ESP32SHT_h
#define ESP32SHT_h
#include <inttypes.h>
#include <Arduino.h>
#include <Wire.h>
#include "SHTSensor.h"

class ESP32SHT35
{

private:
    SHTSensor sht;
    float t;
    float h;
public:
   ESP32SHT35(void);
   boolean read(void);

};
#endif