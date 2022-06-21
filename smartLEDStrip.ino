#include "include/WiFiModule.h"
// #include "include/SmartHomeModule.h"
#include "include/WebServerModule.h"

/*---- LED Strip ----*/
// #include "include/LEDStrip.h"
/*---- LED Strip ----*/

/*---- IO ----*/
#include "include/IO.h"
/*---- IO ----*/

/*---- Button ----*/
#include "include/Button.h"
/*---- Button ----*/

/*---- Web Server----*/
const    long SERVER_TIMEOUT  = 2000; // Define server timeout time in milliseconds (example: 2000ms = 2s)
/*---- Web Server----*/

/*-----------------------------------------------------------------------------*/
/*------------------- Pin Numbers defined inside Contants.h -------------------*/
/*-----------------------------------------------------------------------------*/

void setup(){
  delay(500); // quick wait for initialization
  setupIO();
  setupLEDStrip(); // has to be before setupWiFi to use the strip to indicate we're connected
  setupHandleButtonPress();  
  setupWiFi();
  // setupSmartHomeModule();
  // setupWebServer();
}

void loop(){
  // checkHTTPRequests();
  loopLEDStrip();
}