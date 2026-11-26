#pragma once 
#include <Arduino.h>
#include <Servo.h>




class ServoDriver{ 

    public: 
        ServoDriver();
        void begin();  
        void set(int position); 

    private: 
        Servo servo; 

};