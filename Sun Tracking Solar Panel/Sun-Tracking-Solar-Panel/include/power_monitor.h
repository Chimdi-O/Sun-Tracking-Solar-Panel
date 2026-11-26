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
        void takeReading(int unused );
        //void powerSave(bool enable); 
       

    private: 
        Adafruit_INA219 _sensors[2] = { 
            Adafruit_INA219(0x43), 
            Adafruit_INA219(0x42)
        }; 

        bool _initialised; 
        //bool isValidChannel(uint8_t channel); 
};

