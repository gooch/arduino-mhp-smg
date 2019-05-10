const byte pushTriggerPin = 6;
const byte motorControlPin = 8;
const byte pusherControlPin = 9;

#include "trigger.h"
#include "solenoid.h"
#include "flywheel.h"

Trigger pushTrigger(pushTriggerPin);
Solenoid pusher(pusherControlPin);
Flywheel flywheels(motorControlPin);

void setup() {
//  Serial.begin(9600);
  pushTrigger.setup();
  pusher.setup();
  flywheels.setup();
  pusher.setMode(MODE_BURST);
  pusher.setOnTime(50);
  pusher.setOffTime(100);
}

void loop() {
  pushTrigger.loop();
  if(pushTrigger.isTriggered()){
    flywheels.fire();
    
    if(flywheels.isReady()){
      pusher.activate();
    }
    
  } else {
    flywheels.stop();
    pusher.deactivate();
  }
  pusher.loop();
  flywheels.loop();
//  Serial.print(pusher.state());
//  Serial.print(", ");
//  Serial.println(digitalRead(motorControlPin));
}