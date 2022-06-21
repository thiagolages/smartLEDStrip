#ifndef WIFI_MODULE_H
#define WIFI_MODULE_H

#define SHOW_WIFI_STATUS_ON_LED_STRIP true // must be true or false

#include <ESP8266WiFi.h>
#include <Arduino.h>
#include "LEDStrip.h"
#include "Adafruit_NeoPixel.h"

#define WIFI_SSID         "CLARO_2GBC0AB0"    
#define WIFI_PASS         "E7BC0AB0"

void setupWiFi();
void showColorStatusOnLEDStrip(uint32_t color);

#endif