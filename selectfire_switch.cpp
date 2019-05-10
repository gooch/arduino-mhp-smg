#include "Arduino.h"
#include "selectfire_switch.h"


SelectfireSwitch::SelectfireSwitch(byte pinA, byte pinB){
  _pinA = pinA;
  _pinB = pinB;
}
      
void SelectfireSwitch::setup(){
  pinMode(_pinA, INPUT_PULLUP);
  pinMode(_pinB, INPUT_PULLUP);
}

int SelectfireSwitch::state(){
  return _state;
}

void SelectfireSwitch::loop(){
  if(digitalRead(_pinA) == LOW){
    _state = SINGLE_SHOT;
  } else if(digitalRead(_pinB) == LOW){
    _state = FULL_AUTO;
  } else {
    _state = BURST_FIRE;
  }
}

