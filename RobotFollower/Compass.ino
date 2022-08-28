/*
  Copied from http://www.esp32learning.com/code/an-esp32-and-hmc5883l-sensor-example.php
  on 22.11.21
  Modified by Iwo Kania 
*/
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
 
/* Assign a unique ID to this sensor at the same time */
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);
 
void compSetup()
{
 
  /* Initialise the sensor */
  if(!mag.begin())
  {
  /* There was a problem detecting the HMC5883 ... check your connections */
  Serial.println("No HMC5883 detected");
  while(1);
  }
}
 
float compLoop()
{
  /* Get a new sensor event */
  sensors_event_t event;
  mag.getEvent(&event);
   
  // Hold the module so that Z is pointing 'up' and you can measure the heading with x&y
  // Calculate heading when the magnetometer is level, then correct for signs of axis.
  float heading = atan2(event.magnetic.y, event.magnetic.x); // atan2() returns the tangent inverse in of x and y in radians. used to calculate the radians from point 0,0 which is north
   
  // Once you have your heading, you must then add your 'Declination Angle', which is the 'Error' of the magnetic field in your location.
  // Find yours here: http://www.magnetic-declination.com/
  // Mine is: -13* 2' W, which is ~13 Degrees, or (which we need) 0.22 radians
  // If you cannot find your Declination, comment out these two lines, your compass will be slightly off.
  float declinationAngle = -0.052;
  heading += declinationAngle;
   
  // Correct for when signs are reversed.
  if(heading < 0)
    heading += 2*PI;
   
  // Check for wrap due to addition of declination.
  if(heading > 2*PI)
   heading -= 2*PI;
   
  // Convert radians to degrees for readability.
  float headingDegrees = heading * 180/M_PI;
   
  Serial.print("Heading (degrees): ");
  Serial.println(headingDegrees);
   
  delay(500);
  return headingDegrees0;
}
