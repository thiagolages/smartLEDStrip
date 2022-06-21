#include "../include/LEDStrip.h"

void setupLEDStrip(){
    ledHue = 0;
    ledPowerState = false;

    pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
    
    pinMode(LED_STRIP_BUTTON_PIN, INPUT);   // button to turn LED Strip ON/OFF
    pinMode(LED_STRIP_DATA_PIN  , OUTPUT);
    pinMode(LED_STRIP_SWITCH_PIN, OUTPUT);  // output to LED Strip, to turn it ON/OFF
    
    digitalWrite(LED_STRIP_SWITCH_PIN, LOW);// turn off LED Strip on bootup
}

void loopLEDStrip(){
  pixels.clear(); // Set all pixel colors to 'off'
  for(int i=0; i<LED_STRIP_NUM_LEDS; i++) { // For each pixel...
    pixels.setPixelColor(i, pixels.ColorHSV(ledHue, 255, 255));
  } 
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(LED_STRIP_UPDATE_DELAY); // Pause before next pass through loop
  // Serial.print("ledHue = ");
  // Serial.println(ledHue);
  if (ledHue <= 65535) {ledHue += 1000;} else {ledHue=0;}
}
