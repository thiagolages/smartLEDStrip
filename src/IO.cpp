#include "../include/IO.h"

void setupIO(){
  
  Serial.begin(BAUD_RATE); Serial.printf("\r\n\r\n");

  pinMode(LED_BUILTIN, OUTPUT);           // define LED GPIO as output
  
  digitalWrite(LED_BUILTIN, HIGH);        // turn off LED on bootup (inverse logic)
}