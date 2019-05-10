#include "Arduino.h"
#include "flywheel.h"


Flywheel::Flywheel(byte attachTo){
  _pin = attachTo;
}

bool Flywheel::isReady(){
  return (millis() -_spinStartTime > 50);
}

void Flywheel::fire(){
  if(_state == LOW){
    _spinStartTime = millis();
    _state = HIGH;
    digitalWrite(_pin, _state);
  }
}

void Flywheel::stop(){
  _state = LOW;
  digitalWrite(_pin, _state);
}
      
void Flywheel::setup(){
  pinMode(_pin, OUTPUT);
}

void Flywheel::loop(){
}

