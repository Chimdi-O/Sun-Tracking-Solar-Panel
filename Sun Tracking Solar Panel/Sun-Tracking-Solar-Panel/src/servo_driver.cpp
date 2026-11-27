#include <servo_driver.h>


ServoDriver::ServoDriver(){ 
}

void ServoDriver::begin(){ 
    servo.attach(PIN); 
    servo.write(83);


    while (!set(83)) { 
        delay(700);
    }; 


}

int ServoDriver::set(int position){ 
    Serial.print(position);
  
    /*Serial.print("position: "); 
    Serial.print(position); 
    Serial.print(" current position: "); 
    Serial.print(_current_position); 
    Serial.println("moving!"); */
    
    

    if (position != _current_position){
       

        _current_position = constrain(_current_position,20,146); 

        if ( position > _current_position){ 
   
            servo.write(_current_position+1); 
            _current_position++;
            return 0; 
        }else{ 

            servo.write(_current_position-1); 
            _current_position--; 
            return 0; 
        }

    }
    return 1; 
    

    } 