#ifndef config
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
#define SCREEN_ADDRESS 0x3C

bool display_start(){
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    return false;
  }
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  
  return true;
}

void display_show(char* topic, byte* message, unsigned int length){
  display.setCursor(0, 0);
  display.clearDisplay();
  display.print("Message arrived on topic: ");
  display.print(topic);
  display.print(". Message: ");
/*
  for(int a=0;a<length; a++ ) {
    Serial.print((char)message[a]);
  }
*/
  for(int i=0; i < length; i++){
    display.print((char)message[i]);
  }



  display.display(); 
  delay(2000);
}


#endif