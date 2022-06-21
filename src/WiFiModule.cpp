#include "../include/WiFiModule.h"

const uint32_t wifiConnectionFailureHueColor     = 20000; //map( 0 , 0, 360, 0, 65536);
const uint32_t wifiConnectionSuccessfulHueColor  = 65000; //map(357, 0, 360, 0, 65536);
const uint32_t wifiConnectionWaitingHueColor     = 42000; //map(243, 0, 360, 0, 65536);

const int WIFI_WAIT_TIME_MS = 10*1000;
unsigned long wifiCurrTime = millis();
unsigned long wifiPrevTime = wifiCurrTime;

const short DELAY_LED = 250; /// delay interval between blinkind LED 

const bool showWiFiStatusOnLEDStrip = SHOW_WIFI_STATUS_ON_LED_STRIP;

void setupWiFi() {  

  if (showWiFiStatusOnLEDStrip){
    digitalWrite(LED_STRIP_SWITCH_PIN, HIGH);// turn LED strip ON
  }

  int ledIdx = 0; // indicate WiFi connection status on the strip  

  Serial.printf("\r\n[Wifi]: Connecting");
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    
    Serial.printf(".");
    delay(250);

    if (showWiFiStatusOnLEDStrip){
      pixels.clear();
      wifiCurrTime = millis();

      if((wifiCurrTime - wifiPrevTime) <= WIFI_WAIT_TIME_MS){ // if we're below X seconds of wait
        pixels.setPixelColor(ledIdx, pixels.ColorHSV(wifiConnectionWaitingHueColor, 255, 255));
        pixels.show();
        delay(100);
        
        if (ledIdx >= LED_STRIP_NUM_LEDS){pixels.clear();}
        ledIdx = (ledIdx <= LED_STRIP_NUM_LEDS ? ++ledIdx : 0);
        
      }else{ // when wait is over
        showColorStatusOnLEDStrip(wifiConnectionFailureHueColor);//indicate in the LED Strip the we're connected
        pixels.clear();
        digitalWrite(LED_STRIP_SWITCH_PIN, LOW); // turn LED strip OFF
        break; // break while loop and keep trying later
      }
    }// end if(showWiFiStatusOnLEDStrip)
  }// end while (WiFi.status() != WL_CONNECTED)

  Serial.printf("connected!\r\n[WiFi]: IP-Address is %s\r\n", WiFi.localIP().toString().c_str());
  showColorStatusOnLEDStrip(wifiConnectionSuccessfulHueColor);//indicate in the LED Strip the we're connected

}


void showColorStatusOnLEDStrip(uint32_t color){

  pixels.clear();
  for(int i = 0; i < LED_STRIP_NUM_LEDS; i++) { 
    pixels.setPixelColor(i, color); 
  }  
  pixels.show();   
  
  delay(DELAY_LED);
  pixels.clear();
  pixels.show(); 
  delay(DELAY_LED);
  
  for(int i = 0; i < LED_STRIP_NUM_LEDS; i++) {
    pixels.setPixelColor(i, color); 
  }  
  pixels.show();   
  delay(DELAY_LED);
  pixels.clear();
  pixels.show(); 
  delay(DELAY_LED);
}