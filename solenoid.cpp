#include "Arduino.h"
#include "solenoid.h"


Solenoid::Solenoid(byte attachTo){
  _pin = attachTo;
}
      
void Solenoid::setup(){
  pinMode(_pin, OUTPUT);
  _onTime = 0;
  _offTime = 0;
  _lastStateChange = 0;
}

int Solenoid::setOnTime(int onTime){
  _onTime = onTime;
  return _onTime;
}

int Solenoid::setOffTime(int offTime){
  _offTime = offTime;
  return _offTime;
}

int Solenoid::setMode(int mode){
  _mode = mode;
  return _mode;
}

void Solenoid::activate(){
  _active = true;
}

bool Solenoid::state(){
  return _state;
}

void Solenoid::deactivate(){
  _active = false;
  _currentShotCount = 0;
  if(millis() - _lastStateChange >= _onTime){
    _state = LOW;
    digitalWrite(_pin, _state);
    _lastStateChange = millis();
  }
}

void Solenoid::changeState(){
  _lastStateChange = millis();
  _state = !_state;
  digitalWrite(_pin, _state);
}

void Solenoid::shoot(){
  if(_mode == MODE_FULL_AUTO || _currentShotCount < _mode){
    if(_state == LOW){
      if(millis() - _lastStateChange >= _offTime){
        changeState();
      }
    } else {
      if(millis() - _lastStateChange >= _onTime){
        changeState();
        _currentShotCount++;
      }
    }
  }
}

void Solenoid::loop(){
  if(_onTime == 0) return;
  if(_active) shoot() ;
}

