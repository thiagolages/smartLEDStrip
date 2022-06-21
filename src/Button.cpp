#include "../include/Button.h"

void setupHandleButtonPress(){
    lastBtnPressTime = millis();
    currBtnPressTime = lastBtnPressTime;
    attachInterrupt(digitalPinToInterrupt(LED_STRIP_BUTTON_PIN), handleButtonPress, BUTTON_PRESS_MODE);
}

ICACHE_RAM_ATTR void handleButtonPress() {

  currBtnPressTime = millis(); 

  if ((currBtnPressTime - lastBtnPressTime) >= BUTTON_PRESS_THRESHOLD_MS)  { 
    ledPowerState = !ledPowerState ;

    digitalWrite(LED_BUILTIN          , ledPowerState?LOW:HIGH); // if ledPowerState indicates device turned on: turn on led (builtin led uses inverted logic: LOW = LED ON / HIGH = LED OFF)
    digitalWrite(LED_STRIP_SWITCH_PIN , ledPowerState?HIGH:LOW);

    Serial.printf("Device turned %s (manually via flashbutton)\r\n", ledPowerState?"on ":"off");

    lastBtnPressTime = currBtnPressTime;  // update last button press variable
  } 
}