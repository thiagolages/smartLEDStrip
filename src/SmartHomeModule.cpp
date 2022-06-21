// #include "../include/SmartHomeModule.h"
// #include <Arduino.h>

// void setupSmartHomeModule(){  
//   // // add device to SinricPro
//   // SinricProSwitch& mySmartLEDStrip = SinricPro[SWITCH_ID];

//   // set callback function to device
//   mySmartLEDStrip.onPowerState(onPowerState);

//   // setup SinricPro
//   SinricPro.onConnected([](){ Serial.printf("Connected to SinricPro\r\n"); }); 
//   SinricPro.onDisconnected([](){ Serial.printf("Disconnected from SinricPro\r\n"); });
//   //SinricPro.restoreDeviceStates(true); // Uncomment to restore the last known state from the server.
//   SinricPro.begin(APP_KEY, APP_SECRET);
// }