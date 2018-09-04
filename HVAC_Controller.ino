 // This is what is currently loaded, including the variable speed servo control.

#include <VarSpeedServo.h> 

VarSpeedServo myservo1;    // create servo object to control a servo            
VarSpeedServo myservo2;
VarSpeedServo myservo3;
VarSpeedServo myservo4;

//INPUTS
int zone1 = 1;  //pin1
int zone2 = 2;  //pin2
int zone3 = 3;  //pin3
int zone4 = 4;  //pin4

int fanstatus = 5;


//OUTPUTS
int servo1 = 7;
int servo2 = 8;
int servo3 = 9;
int servo4 = 10;

int relay1 = 11;
//int relay2 = 12;




int speed = 25;
//int s1open = 25;
//int s1closed = 125;
//int s2open = 0;
//int s2closed = 170;
//int potpin = 0;  // analog pin used to connect the potentiometer
//int open = 90; 
//int closed = 0;  

void setup() { 
pinMode(zone1, INPUT_PULLUP);     // Initialize  pin as input with an internal pull-up resistor
pinMode(zone2, INPUT_PULLUP); 
pinMode(zone3, INPUT_PULLUP);
pinMode(zone4, INPUT_PULLUP);
pinMode(fanstatus, INPUT_PULLUP);
 
pinMode(relay1, OUTPUT);
digitalWrite(relay1, LOW);
//pinMode(relay2, OUTPUT);
//digitalWrite(relay2, LOW);

myservo1.attach(servo1);         //Initialize the servo attached to pin
myservo1.write(125, 0, true);
myservo1.write(25, 0, true);
//delay(1000);
//myservo1.write(125, 0, true);
//myservo1.write(25, 0, true);
myservo1.detach();

myservo2.attach(servo2);         //Initialize the servo attached to pin
myservo2.write(125, 0, true);
myservo2.write(25, 0, true);
delay(1000);
//myservo1.write(125, 50, true);
//myservo1.write(25, speed, true);
myservo2.detach();

myservo3.attach(servo3);         //Initialize the servo attached to pin
myservo3.write(125, 0, true);  
myservo3.write(25, 0, true);
//delay(1000);
//myservo3.write(125, 50, true);
//myservo3.write(25, speed, true);
myservo3.detach();

myservo4.attach(servo4);         //Initialize the servo attached to pin
myservo4.write(125, 0, true);  
myservo4.write(25, 0, true);
//delay(1000);
//myservo3.write(125, 50, true);
//myservo3.write(25, speed, true);
myservo4.detach();
} 

int close_Z1(){
myservo1.attach(servo1);
    myservo1.write(25, speed, true);
    //delay(1000);
    myservo1.detach();
}

int open_Z1(){
  myservo1.attach(servo1);
  myservo1.write(125, speed, true);
  //delay(1000);
  myservo1.detach();
}

int close_Z2(){
myservo2.attach(servo2);
    myservo2.write(25, speed, true);
    //delay(1000);
    myservo2.detach();
}

int open_Z2(){
  myservo2.attach(servo2);
  myservo2.write(125, speed, true);
  //delay(1000);
  myservo2.detach();
}

int close_Z3(){
myservo3.attach(servo3);
    myservo3.write(25, speed, true);
    //delay(1000);
    myservo3.detach();
}

int open_Z3(){
  myservo3.attach(servo3);
  myservo3.write(125, speed, true);
  //delay(1000);
  myservo3.detach();
}
int close_Z4(){
myservo4.attach(servo4);
    myservo4.write(25, speed, true);
    //delay(1000);
    myservo4.detach();
}

int open_Z4(){
  myservo4.attach(servo4);
  myservo4.write(125, speed, true);
  //delay(1000);
  myservo4.detach();
}

void loop() {

/////ZONE 1/////
  if(digitalRead(zone1) == LOW) // ZONE IS CALLED TO BE CLOSED,  RELAY IS ENERGIZED CLOSES AND GROUNDS THE PIN = LOW.   LOW -> SHUT ZONE  HIGH -> OPEN ZONE    Default State is OPEN/HIGH
  { 
    close_Z1();
  }
    else
  { 
    open_Z1();
  };

/*
/////ZONE 2/////
//THIS ZONE IS DIFFERENT BECAUSE WE NEED TO TURN ON THE BOOST FAN WHEN THE ZONE IS OPEN BUT ONLY WHEN THE HVAC FAN IS ON. RATHER THAN SIMPLY CLOSE A DAMPER WHEN THE ZONE IS CLOSED
// this first block is to control the relay

if(digitalRead(fanstatus) == LOW //THIS CHECKS IF THE HVAC FAN IS ON LOW=FAN ON
&& digitalRead(zone2) == HIGH)  //IF THE FAN IS ON AND THE ZONE IS SUPPOSED TO BE OPEN THEN THE RELAY WILL TURN ON THE BOOST FAN
  { 
    digitalWrite(relay1, HIGH);  // Turn ON the relay
  }
    else
  { 
    digitalWrite(relay1, LOW);  // Turn OFF the relay
  };

  
//This block is to control a servo is needed.
 if(digitalRead(zone2) == LOW) // ZONE IS CALLED TO BE CLOSED,  RELAY IS ENERGIZED CLOSES AND GROUNDS THE PIN = LOW.   LOW -> SHUT ZONE  HIGH -> OPEN ZONE    Default State is OPEN/HIGH
  { 
    close_Z2();
  }
    else
  { 
    open_Z2();
  };
 */


/////ZONE 3/////
if(digitalRead(zone3) == LOW) // ZONE IS CALLED TO BE CLOSED,  RELAY IS ENERGIZED CLOSES AND GROUNDS THE PIN = LOW.   LOW -> SHUT ZONE  HIGH -> OPEN ZONE    Default State is OPEN/HIGH
  { 
    close_Z3();
  }
    else
  { 
    open_Z3();
  };
/////ZONE 4/////
if(digitalRead(zone4) == LOW) // ZONE IS CALLED TO BE CLOSED,  RELAY IS ENERGIZED CLOSES AND GROUNDS THE PIN = LOW.   LOW -> SHUT ZONE  HIGH -> OPEN ZONE    Default State is OPEN/HIGH
  { 
    close_Z4();
  }
    else
  { 
    open_Z4();
  };



delay(15*1000);  //Pauses the program for the amount of time (in miliseconds) specified as parameter. (There are 1000 milliseconds in a second.)
}
