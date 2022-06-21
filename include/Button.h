#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>
#include "LEDStrip.h"

/*-----------------------------*/
// extern tells the compiler to look for the below definitionsin another file (LEDStrip.h in this case)
extern const short LED_STRIP_SWITCH_PIN;
extern const short LED_STRIP_BUTTON_PIN;
extern bool ledPowerState;
/*-----------------------------*/

#define BUTTON_PRESS_MODE FALLING           // can be RISING, FALLING, CHANGE
const short BUTTON_PRESS_THRESHOLD_MS = 250;// Time to consider a new button press. Since we're using the built-in button, a short time was used because it's already debounced

// These have to be inline to avoid linker problems
inline unsigned long lastBtnPressTime;
inline unsigned long currBtnPressTime;

void setupHandleButtonPress();
ICACHE_RAM_ATTR void handleButtonPress();

#endif