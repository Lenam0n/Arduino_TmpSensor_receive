#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include "config.h"
#include "wifi_cfg.h"
#include "display_cfg.h"

const char* mqtt_server = "10.0.8.32";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

void setup() {
  Serial.begin(SerialBautRate);
  if(wifi() == true && display_start() == true){
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);
    
  }else{
    Serial.println("FEHLER!");
    delay(2000);
    Serial.end();}

}

void callback(char* topic, byte* message, unsigned int length) {
  display.print("UWU");

  display_show(topic, message, length);
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("esp32Display")) {
      Serial.println("connected");
      // Subscribe
      client.subscribe("testtopic/tempreture");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
void loop() {
  if (!client.connected()) { reconnect(); }
  client.loop();
  }