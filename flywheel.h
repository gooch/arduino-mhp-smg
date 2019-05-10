#ifndef Flywheel_h
#define Flywheel_h

#include "Arduino.h"

class Flywheel {

  public:
    Flywheel(byte attachTo);
    void setup();
    void loop();
    void fire();
    void stop();
    bool isReady();

  private:
    byte _pin;
    int _state;
    unsigned long _spinStartTime;
};

#endif
