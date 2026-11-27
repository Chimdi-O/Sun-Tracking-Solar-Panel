#include <servo_driver.h>
#define PIN 9

ServoDriver::ServoDriver(){ 
}

void ServoDriver::begin(){ 
    servo.attach(PIN); 
}

int ServoDriver::set(int position){ 
    if (position != servo.read()){
        servo.write(position); 
     }
    return 0; 
}