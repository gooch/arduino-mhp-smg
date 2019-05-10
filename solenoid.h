#ifndef Solenoid_h
#define Solenoid_h

#include "Arduino.h"

#define MODE_FULL_AUTO  0
#define MODE_BURST      3
#define MODE_SINGLE     1

class Solenoid {

  public:
    Solenoid(byte attachTo);
    void setup();
    void loop();
    int setOnTime(int onTime);
    int setOffTime(int offTime);
    int setMode(int mode);
    void burst(int fireNShots);
    void activate();
    void deactivate();
    void shoot();
    bool state();


  private:
    byte _pin;
    void changeState();
    bool _active;
    unsigned long _lastStateChange;
    int _state;
    int _onTime;
    int _offTime;
    int _currentShotCount;
    int _mode;
};

#endif
