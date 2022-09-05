void handlePhone()
{
 server.send(200, "text/html", homePage);
    Serial.println("Homepage sent");
}

void handlePicker()
{
  server.send(200, "text/html", pagePicker);
}

void handleRoot() {
  
  String coords = "let myLong = ";
  coords += String(myGPS[1], 8);
  coords += "\n";
  coords += "let myLat = ";
  coords +=  String(myGPS[0], 8);
  coords += "\n";
  coords += "let carLong = ";
  coords += String(robGPS[1], 8);
  coords += "\n";
  coords += "let carLat = ";
  coords += String(robGPS[0], 8);
  coords += "\n";
  
 String message = homePage1 + coords + homePage2;
  server.send(200, "text/html", message);
}
void wsSetup(){
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
 

  if (MDNS.begin("esp32")) {
   Serial.println("MDNS responder started");
  }

  Serial.println("Server started");
  
  server.on("/", handlePicker);
  server.on("/HomePage", handleRoot); 
  server.on("/Phone", handlePhone);
  server.on("/data", [](){ //used to collect 
    for (uint8_t i = 0; i < server.args(); i++)
    {
      Serial.println(" " + server.argName(i) + ": " + server.arg(i) + "\n");
      myGPS[i] = server.arg(i).toFloat(); //collects the co-ordinate set into a single array
    }

    server.send(200, "text/html", "<!DOCTYPE html><html><body><h1>Data received</h1></body></html>");
    Serial.println("Data sent");
  });

  server.begin(); 
  Serial.println("Web server started!");
}
 
void wsLoop(){
  server.handleClient();
  delay(2);//allow the cpu to switch to other tasks
}
 
