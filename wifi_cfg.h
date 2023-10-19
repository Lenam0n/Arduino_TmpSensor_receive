#ifndef WIFI_CFG
#define WIFI_CFG
#include "config.h"

bool wifi(){
  int timer = 0;
  while (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssid, password);
    Serial.print(".");
    if(timer < 7){
      delay(WifiDelay);
      timer++;
      
    }else {
      WiFi.disconnect();
      return false;
    }
  }
  Serial.println("");
  Serial.println("WiFi Successfully Connected");
  return true;
  }
void wifi_Error(){
  Serial.println("ERROR - WIFI not Working");
  delay(2000);
  Serial.end();
}
#endif
