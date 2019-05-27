#ifndef FlyWheel_h
#define FlyWheel_h

#include "Arduino.h"
#include <Servo.h>

class FlyWheel {

  public:
    FlyWheel(int attachTo, int max_speed);
    void setup();
    void loop();
    void fire();
    bool isReady();
    int max_speed(int max_speed);
    int getSpeed();

  private:
    byte _pin;
    int _max_speed;
    int _current_speed;
    unsigned long _start_time;
    unsigned long _spin_up;
    Servo _myservo;
};

#endif
