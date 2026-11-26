#include <Arduino.h>
#include "power_monitor.h"
#include "servo_driver.h"
//#include "task.h"
#include <Servo.h>


Servo servodr; 
PowerMonitor powermonitor; 


unsigned long moveservotime = 0; 
unsigned long readingtime = 0; 
int toggle = 0; 

void setup() {
  Serial.begin(115200);
  servodr.attach(9);  
  powermonitor.begin(); 
}

void loop() {
  /*if (millis() - readingtime >= 100){ 
    powermonitor.takeReading(); 
    readingtime = millis(); 
  }  */
  
  if (millis() -  moveservotime >= 7000){ 
    if (toggle == 0){


  
    servodr.write(90);
    delay(20); 
    servodr.write(20);

    
    toggle = 1;  
    } 

    else if (toggle == 1){ 
        
        servodr.write(90);   
        delay(20); 
        servodr.write(146);
        toggle = 0; 
    }
    moveservotime = millis(); 
  }


  
}
