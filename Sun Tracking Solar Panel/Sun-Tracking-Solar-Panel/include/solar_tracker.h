#pragma once 
#include <Arduino.h>


#define SENSOR1 A0 
#define SENSOR2 A1
#define SENSOR3 A2
#define SENSOR4 A3
#define RESISTORVALUE 100e3
#define CURRENTSENSITIVITY 10.0e-9
#define SAMPLENUMBER 10



class SolarTracker{
    public: 
        int sun_angle; 
        int sensor_angles[4] = {0,60,120,180};
        float sensor_readings[SAMPLENUMBER][4]; 
        int reading_num = 0; 
        float average_readings[4] = {0,0,0,0}; 

        SolarTracker(); 
        bool begin();  
        void readSensors(); 
        void calcAverage(); 
        int findAngle(int unused);
    private: 
        int _sensor_pins[4] = {SENSOR1,SENSOR2,SENSOR3,SENSOR4};
        float _offsets[4] = {0,0,0,0}; 

}; 

