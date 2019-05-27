#include "Arduino.h"
#include "flywheel.h"

FlyWheel::FlyWheel(int attachTo, int max_speed)
{
  _pin = attachTo;
  _max_speed = max_speed;
  _start_time = 0;
}

void FlyWheel::fire()
{
  _start_time = millis();
  _current_speed = _max_speed;
}

bool FlyWheel::isReady(){
  return _current_speed == _max_speed;
}

int FlyWheel::getSpeed(){
  return _current_speed;
}

void FlyWheel::setup()
{
  _myservo.attach(_pin);
  _myservo.write(1000);
  _spin_up = 0;
}

void FlyWheel::loop()
{
  unsigned long time_since_start = millis() - _start_time;
  
  if(time_since_start < 5000){
    float p = 1 - (time_since_start / 5000.0);
    _current_speed = 1000 + ((_max_speed - 1000) * p);
  } else {
    _current_speed = 1000;
  }

  _myservo.writeMicroseconds(_current_speed);
  
}

