#include "solar_tracker.h" 


SolarTracker::SolarTracker(){ 
    
  Serial.begin(9600);
  analogReference(DEFAULT);

  for (int i = 0; i < SENSOR_COUNT; i++) {

    sensorAngles[i] =
      i * 180.0 / (SENSOR_COUNT - 1);

    analogRead(SENSOR_PINS[i]);
  }

  delay(10);

  Serial.println(F("BPX65 Sun Tracking Array"));

  calibrateAmbient();
}; 

SolarTracker::begin(){ 



}; 