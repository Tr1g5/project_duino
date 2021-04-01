#include<WiFi.h>
const char *ssid ="Doggo"; // Le nom choisi pour le SSID
const char *password ="password"; // Le mot de passe choisi

// *********************************************************
// *********************************************************

WiFiServer server(80); 

void setup() { 
  pinMode(25,OUTPUT); 
  Serial.begin(9600); 
  WiFi.disconnect();  
  WiFi.mode(WIFI_AP); // seul le mode AP est activé
  WiFi.softAP(ssid, password,7,0,5); // SSID,password,channel,hidden ssid or not, max number of connexions (les trois derniers sont optionnels)
  Serial.println(); 
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());   
  server.begin(); // On démarre le serveur TCP
  Serial.println("SERVEUR TCP DEMARRE");
} 
  
// ******************
// Boucle principale
// ******************

void loop(void) { 
  WiFiClient client = server.available(); 
  if (!client) { 
    return;     
    } 
    Serial.println(""); 
    Serial.println("Nouveau client"); 
    while(client.connected() &&!client.available()){ 
      delay(1);     
      } // Lecture de la première ligne de la requête HTTP
      String req = client.readStringUntil('\r'); // La première ligne de la requête HTTP ressemble à "GET /path HTTP/1.1"
      // Récupération de la partie "/path" en utilisant les espaces
      int addr_start = req.indexOf(' '); 
      int addr_end = req.indexOf(' ', addr_start + 1); 
      if (addr_start ==-1 || addr_end ==-1) { 
        Serial.print("Invalid request: "); Serial.println(req); 
        return; 
      }
      req = req.substring(addr_start + 1, addr_end); 
      Serial.print("Request: "); 
      Serial.println(req);     
      client.flush(); 
  
} 
