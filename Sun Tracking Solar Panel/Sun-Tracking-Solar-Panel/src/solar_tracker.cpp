#include "solar_tracker.h" 
#include <Arduino.h> 




SolarTracker::SolarTracker(){} 

bool SolarTracker::begin(){
     Serial.println("Begin");  

    for(int i = 0; i < SAMPLENUMBER; i++){ 
        Serial.println(reading_num);
   
        readSensors(); 
        delay(300); 
    }
    calcAverage();
    
    for(int i = 0; i < 4; i++){ 
        _offsets[i] = average_readings[i]; 
    } 
   
    return true; 

}


void SolarTracker::calcAverage(){ 
    reading_num = 0; 
    //Serial.println("Average"); 


    float sum; 
   
    for ( int sensor = 0; sensor < 4; sensor++){ 
        sum = 0; 
        
        for (int sample = 0; sample < SAMPLENUMBER; sample++){    
            sum += sensor_readings[sample][sensor]; 

        }
  
        average_readings[sensor] = sum/SAMPLENUMBER; 
    } 
}

void SolarTracker::readSensors(){ 
   
    //Serial.println("readSensors"); 
   
    float sensor_voltages[4]; 
    float sensor_currents[4]; 
    int adc = 0; 
    
    Serial.print("Sensor Readings: "); 
    for( int i = 0; i < 4; i++){ 
        int adc = analogRead(_sensor_pins[i]); 
        sensor_readings[reading_num][i] = adc;  
        //adc = analogRead(_sensor_pins[i]); 
        //sensor_voltages[i] = adc*5.0/1023.0; 
        //sensor_currents[i] = sensor_voltages[i]/ RESISTORVALUE; 
        //sensor_readings[reading_num][i] = adc;
        Serial.print(adc); 
        Serial.print(" "); 

    }
    Serial.print("\n");
    reading_num++; 
    
}

int SolarTracker::findAngle(int unused){ 
    //Serial.println("findAngle");
    //Serial.print("reading_num: ");
    //Serial.print(reading_num);
    //Serial.print("\n");
     
     
    if (reading_num < 9) { 
        readSensors(); 
        
    } else{ 
        //Serial.print("else"); 
        calcAverage(); 

        float weighted_sum = 0; 
        float sum = 0; 
        
        for(int i =0; i < 4; i++){ 
            int temp = average_readings[i]; 
            // - _offsets[i]; 
            if (temp < 0){ 
                temp = 0; 
            }
            weighted_sum += (temp)*sensor_angles[i]; 
            sum += temp;
        }

        if (sum == 0) {
            return sun_angle;
        }
        
        int weighted_average = static_cast<int>( weighted_sum / sum + 1) ; 
        sun_angle = weighted_average; 
    } 
    Serial.print("Sun_angle: "); 
    Serial.print(sun_angle); 
    Serial.print("\n");                                                          
    return sun_angle; 


}
