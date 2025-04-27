#ifndef MAX1301_H
#define MAX1301_H

#include <Arduino.h>
#include <SPI.h>

class MAX1301 {
public:
    enum Scale { CELSIUS, KELVIN, FAHRENHEIT };
    
    MAX1301(int8_t cs_pin);
    float readTempC();
    float readTempF();
    float readTempK();
    void setScale(Scale scale) { currentScale = scale; }
    Scale getScale() { return currentScale; }  // Added this line
    float getTemp();
    
private:
    int8_t _cs;
    Scale currentScale = CELSIUS;
    uint16_t readData();
};

#endif
