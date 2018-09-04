 // edited 8/17/17 by Ian, this uses the standard servo library that does not have speed control adjustment.
 //created to use in a simulator to refine the code.
 
 #include <Servo.h> 

Servo myservo1;    // create servo object to control a servo            
Servo myservo2;
Servo myservo3;
Servo myservo4;

//INPUTS
int zone1 = 1;  //pin1
int zone2 = 2;  //pin2
int zone3 = 3;  //pin3
int zone4 = 4;  //pin4

int fanstatus = 5;


//OUTPUTS
int servo1pin = 7;
int servo2pin = 8;
int servo3pin = 9;
int servo4pin = 10;

int relay1 = 11;
//int relay2 = 12;



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

myservo1.attach(servo1pin);         //Initialize the servo attached to pin
myservo1.write(125);
myservo1.write(25);
myservo1.detach();

myservo2.attach(servo2pin);         //Initialize the servo attached to pin
myservo2.write(125);
myservo2.write(25);
myservo2.detach();

myservo3.attach(servo3pin);         //Initialize the servo attached to pin
myservo3.write(125);  
myservo3.write(25);
myservo3.detach();

myservo4.attach(servo4pin);         //Initialize the servo attached to pin
myservo4.write(125);  
myservo4.write(25);
myservo4.detach();
} 

int close_Z1(){
myservo1.attach(servo1pin);
    myservo1.write(25);
    myservo1.detach();
}

int open_Z1(){
  myservo1.attach(servo1pin);
  myservo1.write(125);
  myservo1.detach();
}

int close_Z2(){
myservo2.attach(servo2pin);
    myservo2.write(25);
    myservo2.detach();
}

int open_Z2(){
  myservo2.attach(servo2pin);
  myservo2.write(125);
  myservo2.detach();
}

int close_Z3(){
myservo3.attach(servo3pin);
    myservo3.write(25);
    myservo3.detach();
}

int open_Z3(){
  myservo3.attach(servo3pin);
  myservo3.write(125);
  myservo3.detach();
}
int close_Z4(){
myservo4.attach(servo4pin);
    myservo4.write(25);
    myservo4.detach();
}

int open_Z4(){
  myservo4.attach(servo4pin);
  myservo4.write(125);
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
