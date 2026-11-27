

#include <Arduino.h>
#include "power_monitor.h"
#include "servo_driver.h"
#include "task.h"
#include "solar_tracker.h"


ServoDriver servodriver; 
//PowerMonitor powermonitor; 
SolarTracker solartracker; 


Task<ServoDriver> servo_task = {500,0, &servodriver, &ServoDriver::set,0}; 
//Task<PowerMonitor> power_task {5000,0, &powermonitor, &PowerMonitor::takeReading}; 
Task<SolarTracker> track_task {100,0, &solartracker, &SolarTracker::findAngle,0}; 


template <typename T> 
int executeTask(Task <T> &task, int argument){ 
  if(millis() - task.last_run_time >= task.interval){ 
     task.last_run_time = millis(); 
     Serial.print(argument);
     task.last_output = (task.object->*task.execute)(argument);
     return task.last_output; 
    
  }
  return task.last_output; 
}

unsigned long moveservotime = 0; 
unsigned long readingtime = 0; 
int sun_angle = 0;

void setup() {
  Serial.begin(115200);


  while (!Serial) { // program does not run until Serial opens 
    delay(1);
  }

  Serial.println("setup"); 
  servodriver.begin();  
  //powermonitor.begin(); 
  solartracker.begin(); 
  delay(2000);
}

void loop() {
  //Serial.println("loop");
  //executeTask(power_task,0); 
  sun_angle = executeTask(track_task,0);  

  executeTask(servo_task,sun_angle);


}


  

