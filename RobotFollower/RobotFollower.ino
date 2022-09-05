#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
#include <Adafruit_GPS.h>
#include <ESP32Servo.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include "PhoneGPS.h"
#include "MainPage.h"
#include "Pagepicker.h"

#define GPSSerial Serial2 //sets the GPS to serial 2 pins

Adafruit_GPS GPS(&GPSSerial);
uint32_t timer = millis();
uint32_t timer2 = millis();
uint32_t timer3 = millis();

const char* ssid     = "gamertime";
const char* password = "12345678";

Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

Servo steerServo; //sets a servo object called steerServo
WebServer server(80);   //instantiate server at port 80 (http port)

int servoPos; //servo posistion
int servoPin = 19; //pin of the servo cotrol
int motor = 27; //motor pin
int enMotor = 26; //motor enable pin

float robGPS[2] = {0, 0};
float robDir;
float myDir;
float myGPS[2] = {0, 0}; 
double distance;

void setup()
{
  Serial.begin(115200);
  wsSetup();
  motorSetup();
 compSetup();
 GPSsetup();
}

void loop() 
{
  wsLoop();
  GPSloop();
  if(GPS.fix)
  {
  robDir = compLoop();
  if(myGPS[0] != 0)
  {
    myDir = getTargetDir(robGPS[0], robGPS[1], myGPS[0], myGPS[1], robDir);
    distance = getDistance(robGPS[0], robGPS[1], myGPS[0], myGPS[1]);
    setDir(robDir, myDir);
  }
  }
}
