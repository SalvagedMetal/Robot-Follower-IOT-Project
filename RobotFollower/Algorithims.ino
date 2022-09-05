//Algorythms such as getting the angle of the robot follower, distance and angle needed.

 double getDistance(float lat1, float long1, float lat2, float long2)
  {
    //distance = sqrt((robolat - targetlat)^2 +(robotlong - targetlong)^2)
    double totalLat = lat1 - lat2;
    double totalLong = long1 - long2;
    double distance = sqrt(pow(totalLat, 2) + pow(totalLong, 2)) * 11139; //11139 refers to converting from gps degrees to meters
    Serial.print("target distance: ");
    Serial.print(distance);
    Serial.print("\n");
    return distance;
  }
  float getTargetDir(float lat1, float long1, float lat2, float long2, float robotDir)
  {
    float targAngle = 0;
    float totalLat = lat1 - lat2;
    float totalLong = long1 - long2;
    //calculate the angle of the target
    float angleDif = pow((tan(totalLat) / totalLong), -1);
     //target angle = tan^-1((robotlat-targetlat)/(robolong-targetlong))
   if(angleDif + robotDir > 360) //when the total angle goes past 360
   {
    targAngle = angleDif + robotDir - 360;
    Serial.print("target angle: ");
    Serial.print(targAngle);
    Serial.print("\n");
    return targAngle;
   }
   else if(angleDif + robotDir < 0) //when the total angle is less than 0
   {
    targAngle = angleDif + robotDir + 360;
    Serial.print("target angle: ");
    Serial.print(targAngle);
    Serial.print("\n");
    return targAngle;
   }
    else
   {
    targAngle = angleDif + robotDir;
    Serial.print("target angle: ");
    Serial.print(targAngle);
    Serial.print("\n");
    return targAngle;
   }
  }
  
  
  //target angle = tan^-1((robotlat-targetlat)/(robolong-targetlong))
  //current angle = compass
  //distance = sqrt((robolat - targetlat)^2 +(robotlong - targetlong)^2)
