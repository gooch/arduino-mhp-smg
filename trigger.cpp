#include "Arduino.h"
#include "trigger.h"


Trigger::Trigger(byte attachTo){
  _pin = attachTo;
}

// public accessor for trigger state
bool Trigger::isTriggered(){
  return _triggered;
}
      
void Trigger::setup(){
  pinMode(_pin, INPUT_PULLUP);
  _state = HIGH;
  _triggered = false;
}

void Trigger::loop(){
  // low is on because PULLUP
  int _prevState = _state;
  _state = digitalRead(_pin);

  if (_prevState == HIGH && _state == LOW){
    // state has changed, begin timing
    _buttonDownMs = millis();
  } else if(_prevState == LOW && _state == LOW){
    // state has remained low, check duration
    if(millis() - _buttonDownMs > 25){
      // state has been low for more than 50ms, go time
      _triggered = true;
    }
  } else {
    _triggered = false;
  }
}

