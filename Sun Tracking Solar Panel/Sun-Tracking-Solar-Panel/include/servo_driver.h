#pragma once 
#include <Arduino.h>
#include <Servo.h>
#define PIN 9 




class ServoDriver{ 

    public: 
        ServoDriver();
        void begin();  
        int set(int position); 

    private: 
        Servo servo; 
        int _current_position = 83;

};