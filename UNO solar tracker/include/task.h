#pragma once 

struct Task{ 
  unsigned long interval; 
  unsigned long last_run_time; 
  void (*execute)(); 
}