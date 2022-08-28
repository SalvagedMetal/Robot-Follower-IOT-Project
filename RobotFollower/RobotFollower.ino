#include "WebSock.h"

int robotDir;
void setup()
{
  Serial.begin(115200);
  wsSetup();
  motorSetup();
  compSetup();
}

void loop() 
{
 robotDir = compLoop();
   wsLoop();
}
