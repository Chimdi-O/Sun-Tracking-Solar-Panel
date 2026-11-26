

#include <Arduino.h>
#include "power_monitor.h"
#include "servo_driver.h"
#include "task.h"

/*
void setup(void) 
{
  Serial.begin(115200);
  while (!Serial) {
      // will pause Zero, Leonardo, etc until serial console opens
      delay(1);
  }
    
  Serial.println("Hello!");
*/

ServoDriver servodriver; 
PowerMonitor powermonitor; 


Task<ServoDriver> servo_task = {100,0, &servodriver, &ServoDriver::set}; // servoTask

Task<PowerMonitor> power_task {5000,0, &powermonitor, &PowerMonitor::takeReading}; // PowerMonitor



template <typename T> 
void executeTask(Task <T> task, int argument){ 
  if(millis() - task.last_run_time >= task.interval){ 
     task.execute(argument); 
  }
};

unsigned long moveservotime = 0; 
unsigned long readingtime = 0; 

void setup() {
  Serial.begin(115200);
  servodriver.begin();  
  powermonitor.begin(); 
}

void loop() {

  executeTask(power_task,0); 
  executeTask(servo_task,90); 


}


  

