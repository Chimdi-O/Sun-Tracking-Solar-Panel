#include "power_monitor.h"
#include <Arduino.h>

PowerMonitor::PowerMonitor()
    :_initialised{false}
    {} 

bool PowerMonitor::begin(TwoWire *the_wire){ 
    bool all_ok = true; 

    if (! _sensors[0].begin(the_wire)){ 
        all_ok = false; 
    }else if(! _sensors[1].begin(the_wire) ){ 
        all_ok = false;
    }else if (! _sensors[2].begin(the_wire)){ 
        all_ok = false; 
    }

    return all_ok;

}  

int PowerMonitor::takeReading(int unused){ 

    Serial.print("Arduino: ");
    Serial.print(_sensors[0].getPower_mW());
    Serial.print("  Motor:");
    Serial.print(_sensors[1].getPower_mW());
    Serial.print("  Tracking System: ");
    Serial.print(_sensors[2].getPower_mW());
    Serial.print("  Solar Panel: ");
    Serial.print(_sensors[3].getPower_mW());
    Serial.print("\n");

    return 0;

}