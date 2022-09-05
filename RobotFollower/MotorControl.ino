
void motorSetup()
{ 
  ESP32PWM::allocateTimer(0); //allocates timers to the servo
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  steerServo.setPeriodHertz(50); //sets the frequency of the servo object
  steerServo.attach(servoPin, 1000, 2000); //sets the min and max pulse lengths in ms for the servo pin
  pinMode(motor, OUTPUT);   
  pinMode(enMotor, OUTPUT);

  //calibrates the wheels to be straight
  for (servoPos = 0; servoPos <= 180; servoPos++)
  {
    steerServo.write(servoPos); //writes the desired angle of the servo to the pin
    delay(15);
  }
  while (servoPos > 90)
  {
    steerServo.write(servoPos);
    delay(15);
    servoPos--;
  }
} 

void mForward()
{
  digitalWrite(enMotor, LOW);
  digitalWrite(motor, HIGH);
}

void mStop()
{
  analogWrite(enMotor, 0);
}

void steerRight()
{
  while(servoPos >= 0)
  {
     steerServo.write(servoPos);
     delay(15);
     servoPos--;
  }
}

void steerStraight()
{
  if (servoPos > 90)
    while (servoPos != 90)
    {
      steerServo.write(servoPos);
      delay(15);
      servoPos--;
    }
   else if (servoPos < 90)
    while (servoPos != 90)
    {
      steerServo.write(servoPos);
      delay(15);
      servoPos++;
    }
}

void steerLeft()
{
  while(servoPos <= 180)
  {
     steerServo.write(servoPos);
     delay(15);
     servoPos++;
  }
}

void setDir(float dir1, float dir2)
  {
    //figure out which quadrant the robot and targets are
    if((dir1 < (dir2 + 3)) && (dir1 > (dir2 - 3)))//gives the robot a +-3 degrees of error
    {
     steerStraight();
     mStop();
     drive(distance);
    }
    else
    {
      if(dir1 < dir2)
      {
        steerLeft();
        mForward();
      }
      if(dir1 > dir2)
      {
        steerRight();
        mForward();
      }
    }
  }
  void drive(float dis)
  {
   int sec = (dis * 1000) / 0.455 ; // m/s is 0.455 and multiply by 1000 to get it in milliseconds
   mForward();
   if ((millis() - timer3) > sec) //will stop after "sec" time passed
   {
    mStop();
    timer3 = millis();
   }
  }
