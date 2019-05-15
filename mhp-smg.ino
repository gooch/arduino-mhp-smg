const int revTriggerPin = 6;
const int pushTriggerPin = 9;
const int motorControlPin = 8;
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
Flywheel flywheels(motorControlPin);

void setup() {
  Serial.begin(9600);
  revTrigger.setup();
  pushTrigger.setup();
  pusher.setup();
  flywheels.setup();
  pusher.setMode(MODE_FULL_AUTO);
  pusher.setOnTime(50);
  pusher.setOffTime(100);
///  selectfireSwitch.setup();
}

void loop() {
  revTrigger.loop();
  pushTrigger.loop();

  if(revTrigger.isTriggered()){
    flywheels.fire();
  } else {
    flywheels.stop();
  }
  
  if(pushTrigger.isTriggered()){
    if(flywheels.isReady()){
      pusher.activate();
    }
  } else {
    pusher.deactivate();
  }
  pusher.loop();
  flywheels.loop();
  Serial.print(pusher.state());
  Serial.print(", ");
  Serial.println(digitalRead(motorControlPin));
}
