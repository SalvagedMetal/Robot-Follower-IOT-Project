#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include "scopeLam.h"
#include "page2.h"

const char *ssid = "yourAP";
const char *password = "12345678";
WebServer server(80);   //instantiate server at port 80 (http port)

void wsSetup(){
  Serial.println("Configuring access point...");
  // You can remove the password parameter if you want the AP to be open.
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();

  Serial.println("Server started");
  
  server.on("/", [](){
    server.send(200, "text/html", homePage);
    Serial.println("Homepage sent");
  });

  server.on("/data", [](){
    for (uint8_t i = 0; i < server.args(); i++)
    {
      Serial.println(" " + server.argName(i) + ": " + server.arg(i) + "\n");
    }

    server.send(200, "text/html", "<!DOCTYPE html><html><body><h1>Data received</h1></body></html>");
    Serial.println("Data sent");
  });
 
  server.on("/page2", [](){
    server.send(200, "text/html", page2);
    Serial.println("page2 sent");
  });

  server.begin(); 
  Serial.println("Web server started!");
}
 
void wsLoop(){
  server.handleClient();
}
 
