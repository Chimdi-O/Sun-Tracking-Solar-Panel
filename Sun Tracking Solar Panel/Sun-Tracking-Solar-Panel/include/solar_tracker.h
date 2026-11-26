#pragma once 


#include <Arduino.h>



class SolarTracker{
    public: 
        
        SolarTracker(); 
        bool begin(); 
        int sun_angle; 
        int find_angle(); 
    
    private: 
        int offset1; 
        int offset2; 
        int offset3;
        int offset4; 



}; 

