#include "WiFi.h"

const char* ssid="uwu";
const char* password="password";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("");
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED){
    Serial.println("Tentative de connexion...");
    delay(1000);
  }
    Serial.println("Connecté au réseau wifi !");
}

void loop() {
  // put your main code here, to run repeatedly:

}
