#include "ESP32SHT35.h"

ESP32SHT35::ESP32SHT35()
{
    Wire.begin();
    sht.init();
    sht.setAccuracy(SHTSensor::SHT_ACCURACY_HIGH); // only supported by SHT3x
}
boolean ESP32SHT35::read()
{
    if (sht.readSample()) {
        h = sht.getHumidity();
        t = sht.getTemperature();
        return true;
    }

    return false;
}

float ESP32SHT35::getH()
{
    return h;
}

float ESP32SHT35::getT()
{
    return t;
}