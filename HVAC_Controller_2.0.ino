
// VarSpeedServo - Version: Latest 
#include <VarSpeedServo.h>

//Servo Objects
int numServos = 4; //Change number of servos you want to use here
VarSpeedServo servo[4]; //Change number of servos you want to use here

//SERVO OUTPUTS
int ServoPin[] = {8,9,10,12}; //Choose digital pins used for servos

//INPUTS
int input01 = 2, input02 = 3, input03 = 4, input04 = 5, input05 = 6;

//States
int zone01State, zone02State, zone03State, zone04State, lastZone01State, lastZone02State, lastZone03State, lastZone04State;

int speed = 25;
int speedTest = 25;

//=======================================================

void setup(){
  // initialize the inputs as a inputs
  pinMode(input01, INPUT_PULLUP);
  pinMode(input02, INPUT_PULLUP);
  pinMode(input03, INPUT_PULLUP);
  pinMode(input04, INPUT_PULLUP);
  pinMode(input05, INPUT_PULLUP);

  servoTest();
}

//======================================================

void loop() {
  // read the zone states:
  zone01State = digitalRead(input01);
  zone02State = digitalRead(input02);
  zone03State = digitalRead(input03);
  zone04State = digitalRead(input04);
    
  if (zone01State != lastZone01State) { //compare the 2 states
     // if current state is not equal last state then state has changed, do something...
    // Check what it should be and move servo accordingly
    zone01State == LOW ? closeZone(0) : openZone(0);
    // ZONE IS CALLED TO BE CLOSED, RELAY IS ENERGIZED/ON = LOW.  // LOW -> SHUT ZONE HIGH -> OPEN ZONE Default State is OPEN/HIGH
    //rememeber 0=1 1=2 because you are using an array that starts at 0

    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastZone01State = zone01State;

  if (zone02State != lastZone02State) {
    zone02State == LOW ? closeZone(1) : openZone(1);
    delay(50);
  }
  lastZone02State = zone02State;

  if (zone03State != lastZone03State) {
    zone03State == LOW ? closeZone(2) : openZone(2);
  delay(50);
  }
  lastZone03State = zone03State;

  if (zone04State != lastZone04State) {
    zone04State == LOW ? closeZone(3) : openZone(3);
  delay(50);
  }
  lastZone04State = zone04State;
}


int closeZone(int i){
    servo[i].attach(ServoPin[i]);
    servo[i].write(25, speed, true);
    delay(1000);
    servo[i].detach();
}

int openZone(int i){
    servo[i].attach(ServoPin[i]);
    servo[i].write(125, speed, true);
    delay(1000);
    servo[i].detach();
}

int servoTest(){
    for (int i = 0; i < numServos; i++){
        delay(5000); // so i can get to that servo to watch it
        servo[i].attach(ServoPin[i]);
        servo[i].write(25, speedTest, true);
        //delay(1000);
        servo[i].write(125, speedTest, true);
        //delay(1000);
        servo[i].write(25, speedTest, true);
        //delay(1000);
        servo[i].write(125, speedTest, true); //finish in the open position.
        //delay(1000);
        servo[i].detach();
    }
}