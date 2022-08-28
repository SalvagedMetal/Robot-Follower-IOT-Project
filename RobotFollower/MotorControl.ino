 #include <ESP32Servo.h>

Servo steerServo; //sets a servo object called steerServo

int servoPos; //servo posistion
int servoPin = 14; //pin of the servo cotrol
int motor = 27; //motor pin
int enMotor = 26; //motor enable pin

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
  while (servoPos != 90)
  {
    steerServo.write(servoPos);
    delay(15);
    servoPos--;
  }
} 

void mForward()
{
  analogWrite(enMotor, 255);
  digitalWrite(motor, HIGH);
}

void mStop()
{
  analogWrite(enMotor, 0);
}

void steerLeft()
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



void steerRight()
{
  while(servoPos <= 180)
  {
     steerServo.write(servoPos);
     delay(15);
     servoPos++;
  }
}
