const int revTriggerPin = 6;
const int pushTriggerPin = 9;
const int motorControlPinA = 7;
const int motorControlPinB = 8;
const int pusherControlPin = 5;
//const byte sfSwitchA = 3;
//const byte sfSwitchB = 4;

#include "trigger.h"
#include "solenoid.h"
#include "flywheel.h"
//#include "selectfire_switch.h"

Trigger revTrigger(revTriggerPin);
Trigger pushTrigger(pushTriggerPin);
Solenoid pusher(pusherControlPin);
FlyWheel flywheelA(motorControlPinA, 2000);
FlyWheel flywheelB(motorControlPinB, 2000);

void setup() {
  Serial.begin(9600);
  revTrigger.setup();
  pushTrigger.setup();
  pusher.setup();
  flywheelA.setup();
  flywheelB.setup();
  pusher.setMode(MODE_FULL_AUTO);
  pusher.setOnTime(50);
  pusher.setOffTime(100);
///  selectfireSwitch.setup();
  delay(6000);
}

void loop() {
  revTrigger.loop();
  pushTrigger.loop();

  if(revTrigger.isTriggered()){
    flywheelA.fire();
    flywheelB.fire();
  } else {
    pusher.deactivate();
  }
  
  if(pushTrigger.isTriggered()){
    if(flywheelA.isReady() && flywheelB.isReady()){
      pusher.activate();
    }
  } else {
    pusher.deactivate();
  }
  pusher.loop();
  flywheelA.loop();
  flywheelB.loop();
  Serial.print(flywheelA.getSpeed());
  Serial.print(", ");
  if(pusher.state()){
    Serial.println(2000);
  } else {
    Serial.println(1000);
  }
}
