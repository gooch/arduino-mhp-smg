#include "Arduino.h"
#include "flywheel.h"


Flywheel::Flywheel(byte attachTo){
  _pin = attachTo;
}

bool Flywheel::isReady(){
  return _state && (millis() -_spinStartTime > 500);
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

