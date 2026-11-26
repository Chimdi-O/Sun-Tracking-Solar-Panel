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
        all_ok = false;} 

    return all_ok;

}  

void PowerMonitor::takeReading(){ 
    /*Reading{ 
        _sensor.getShuntVoltage_mV(),
        _sensor.getBusVoltage_V(),
        _sensor.getCurrent_mA(),
        _sensor.getPower_mW()
    };*/
    Serial.print("MOTOR:");
    Serial.print(_sensors[0].getPower_mW());
    Serial.print("  PANEL:");
    Serial.print(_sensors[1].getShuntVoltage_mV());
    Serial.print("\n");

}