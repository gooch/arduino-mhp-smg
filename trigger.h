#ifndef Trigger_h
#define Trigger_h

#include "Arduino.h"

class Trigger {

  public:
    Trigger(byte attachTo);
    bool isTriggered();
    void setup();
    void loop();


  private:
    // raw state of the pin, non-debounced
    int _state;
    int _prevState;
    // debounced pin state
    bool _triggered;
    byte _pin;
    unsigned long _buttonDownMs;
};

#endif
