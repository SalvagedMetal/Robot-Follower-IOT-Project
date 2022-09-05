
void GPSsetup()
{
  GPS.begin(9600);
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA); //get altitude and fix data
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);//update rate set to 1Hz
  GPS.sendCommand(PGCMD_ANTENNA);//antenna status update
  delay(1000);
}

void GPSloop() {
    
    char c = GPS.read();
    if (c) Serial.print(c);
    // if a sentence is received, we can check the checksum, parse it...
    if (GPS.newNMEAreceived()) {
    // a tricky thing here is if we print the NMEA sentence, or data
    // we end up not listening and catching other sentences!
    // so be very wary if using OUTPUT_ALLDATA and trying to print out data
    Serial.print(GPS.lastNMEA()); // this also sets the newNMEAreceived() flag to false
    if (!GPS.parse(GPS.lastNMEA())) // this also sets the newNMEAreceived() flag to false
      return; // we can fail to parse a sentence in which case we should just wait for another
  }

  if (millis() - timer > 2000) //updates every 2 seconds
  {
    if(!GPS.fix)
    {
    Serial.print("connecting GPS to satellites...\n");
    }
    timer = millis(); // reset the timer
    if (GPS.fix)
    {
      Serial.print("\n");
      Serial.print("Location: ");
      float GPSlat = GPS.latitude;
      float GPSlong = GPS.longitude;
      Serial.print(GPSlat, 6); //the number refers to the the number of decimal digits allowed
      Serial.print(GPS.lat); //distiquises as north or south
      Serial.print(", ");
      Serial.print(GPSlong, 6);
      Serial.println(GPS.lon); //distiguishes as east or west
      Serial.print("Angle: "); Serial.println(GPS.angle);
      Serial.print("Altitude: "); Serial.println(GPS.altitude);
      Serial.print("Satellites: "); Serial.println((int)GPS.satellites);
      Serial.print("\n\n");
      if(GPS.lat == 'S')
        robGPS[0] = GPSlat * -1;
      else
        robGPS[0] = GPSlat;
        
      if(GPS.lon == 'W')
        robGPS[1] = GPSlong * -1;
      else
        robGPS[1] = GPSlong;
    }
  }
}
