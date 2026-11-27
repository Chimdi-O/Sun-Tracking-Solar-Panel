#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_INA219.h>

struct Reading{ 
    float bus_voltage; //  V
    float shunt_voltage; // mV
    float current; // mA 
    float power; // mW 
};



class PowerMonitor{
    public: 
        PowerMonitor(); 
        bool begin(TwoWire *theWire = &Wire); 
        int takeReading(int unused );
        //void powerSave(bool enable); 
       

    private: 
        Adafruit_INA219 _sensors[4] = { 
            Adafruit_INA219(0x43), 
            Adafruit_INA219(0x42),
            Adafruit_INA219(0x41), 
            Adafruit_INA219(0x40)
        }; 

        bool _initialised; 
        //bool isValidChannel(uint8_t channel); 
};

