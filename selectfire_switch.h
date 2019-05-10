#ifndef SelectfireSwitch_h
#define SelectfireSwitch_h

#include "Arduino.h"

#define SINGLE_SHOT 0
#define BURST_FIRE  1
#define FULL_AUTO   2

class SelectfireSwitch {

  public:
    SelectfireSwitch(byte pinA, byte pinB);
    void setup();
    void loop();
    int state();

  private:
    byte _pinA;
    byte _pinB;
    int _state;
};

#endif
