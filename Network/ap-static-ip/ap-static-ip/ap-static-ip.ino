// Connect
#include <ESP8266WiFi.h>
#include "secrets.h";

// Configure generated WiFi
// const char *ssid = "SSID";
// const char *password = "PASSWORD";

IPAddress ip(192,168,1,200);     
IPAddress gateway(192,168,1,1);   
IPAddress subnet(255,255,255,0);   

void setup() 
{
  Serial.begin(115200);
  delay(10);
  Serial.println();
 
  WiFi.mode(WIFI_STA);
  WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to:\t");
  Serial.println(ssid); 

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(200); 
  Serial.print('.');
  }

  // Show success message and assigned IP address
  Serial.println("Connection established");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());
}

void loop() 
{
}