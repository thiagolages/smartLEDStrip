#ifndef WEB_SERVER_MODULE_H
#define WEB_SERVER_MODULE_H

#include "SinricPro.h"
#include "SinricProSwitch.h"


// The following should be obtained from your account at https://portal.sinric.pro/
/*-----------------------------------------------*/
#define APP_KEY           "YOUR_APP_KEY_HERE"
#define APP_SECRET        "YOUR_APP_SECRET_HERE"   
#define SWITCH_ID         "YOUR_SWITCH_ID_HERE"
/*-----------------------------------------------*/

// get Switch device back
SinricProSwitch& mySwitch = SinricPro[SWITCH_ID];

extern bool ledPowerState;

unsigned long serverCurrTime   = millis();
unsigned long serverPrevTime  = 0; 
const    long timeoutTime   = 2000; // Define timeout time in milliseconds (example: 2000ms = 2s)

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output5State = "off";
String output4State = "off";

void setupSinricPro();
void initWebServer();
void checkHTTPRequests();
void handleButtonPress();
bool onPowerState(const String &deviceId, bool &state);

#endif