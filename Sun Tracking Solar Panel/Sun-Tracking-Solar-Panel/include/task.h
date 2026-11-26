
#pragma once 
template <typename T> 

struct Task{ 
  unsigned long interval;
  unsigned long last_run_time; 
  T* object;
  void (T::*execute)(int); 
};