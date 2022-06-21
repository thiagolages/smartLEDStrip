#ifndef LED_STRIP_H
#define LED_STRIP_H

#include <Adafruit_NeoPixel.h>

/*---- LED Strip ----*/
const short LED_STRIP_BUTTON_PIN  = 0;  // To turn the LED Strip ON/OFF (0 is FLASH button)
const short LED_STRIP_SWITCH_PIN  = 4;  // To switch LED Strip ON/OFF
const short LED_STRIP_DATA_PIN    = 5;  // To actually control the LED's colors
const short LED_STRIP_SIZE_M      = 3;
const short LED_STRIP_LEDS_PER_M  = 30;
const short LED_STRIP_UPDATE_DELAY= 50; // Time (in milliseconds) to pause between updates
const short   LED_STRIP_NUM_LEDS  = LED_STRIP_LEDS_PER_M * LED_STRIP_SIZE_M;

// These have to be inline to avoid linker problems
inline unsigned int    ledHue;
inline bool            ledPowerState;
inline Adafruit_NeoPixel pixels(LED_STRIP_NUM_LEDS, LED_STRIP_DATA_PIN, NEO_BGR + NEO_KHZ800);
/*---- LED Strip ----*/

void setupLEDStrip();

void loopLEDStrip();

#endif