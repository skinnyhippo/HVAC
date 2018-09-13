#include <Servo.h>

int numServos = 4; //Change number of servos you want to use here
Servo servo[4]; //Change number of servos you want to use here

int ServoPin[] = {8,9,10,11}; //Choose digital pins used for servos

void setup() 
{
  
}


void loop() 
{
  for (int i = 0; i < numServos; i++)
  {
    servo[i].attach(ServoPin[i]);
    servo[i].write(25);
    delay(2000);
    servo[i].write(125);
    delay(2000);
    servo[i].detach();

  }
}




