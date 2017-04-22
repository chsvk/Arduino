

// Including the library files required for the sensors
// NewPing library is used to send periodic pulses to the ultrasonic sensors
// SharpIR library is used to workd with the sharpIR module
#include <NewPing.h>
#include <SharpIR.h>
// Declaring the pins on the board which we are going to use.
#define TRIGGER_PIN  10  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 500 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define ir A4
#define model 1080
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
SharpIR SharpIR(ir, model);
int a,b;
int lm1=3;
int lm2=5;
int rm1=6;
int rm2=9;

// This method measures the distance of the wall from the sharp IR sensor.
void sharp()
{
   delay(20);   

  unsigned long pepe1=millis();  // takes the time before the loop on the library begins

  a=SharpIR.distance();  // this returns the distance to the object you're measuring


  Serial.print("Mean distance: ");  // returns it to the serial monitor
  Serial.println(a);
  
  
 //unsigned long pepe2=millis()-pepe1;  // the following gives you the time taken to get the measurement
 // Serial.print("Time taken (ms): ");
 // Serial.println(pepe2);  
}


// This method measures the distance of the wall from the ultrasonic sensor.
void pinger()
{
   delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  b=uS / US_ROUNDTRIP_CM;
  Serial.print(b); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
}


// This method sets the rover on the straight line and monitors it from loosing its track
void set_straight()
{
  if(b==12)
  {
    Serial.println("HELD STRAIGHT");
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
  }
  if((b > 12) && (b<15))
  {
    Serial.println("setting left");
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    analogWrite(rm1,180);
    digitalWrite(rm2,LOW);
    delay(1);
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,LOW);
    delay(1);
  }
  if((b < 12) && (b > 8))
  {
    Serial.println("setting right");
    analogWrite(lm1,180);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    delay(1);
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,LOW);
    delay(1);
  }
}


// This method changes the direction of the rover to left and sets it in accordance with the straight() function.
void left()
{
  Serial.println("taking left");
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(250);
  if( ( a < 16) || (b > 16))
  {
    Serial.println("adjusting turn left");
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(1);
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
  delay(1);
  }
}


// This method changes the direction of the rover to right and sets it in accordance with the straight() function.
void right()
{
  Serial.println("taking right");
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
  delay(500);
  if( b > 16)
  {
    Serial.println("adjusting turn right");
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
  }
}


//This method is executed only once and includes all the intializing and setting the modes of the pins.
void setup() {
  // put your setup code here, to run once:
  //Initializing the serial monitor
  Serial.begin(9600);
   pinMode(lm1,OUTPUT);
   pinMode(lm2,OUTPUT);
   pinMode(rm1,OUTPUT);
   pinMode(rm2,OUTPUT);
}


// This code is repeated until the end of runTime.
void loop() {
  // Reference point to come back incase of change in conditions
 check:
 // Calling the sharp and pinger functions to get the distances of walls from the ultrasonic and sharpIR sensors.
 sharp();
 pinger();
 //delay(200);
 if((a > 15) && ((b >= 8) && (b<=16)))
 {
  // Setting up the path of the rover depending on the values of the sharp and ultrasonic sensors.
  set_straight();
  sharp();
  pinger();
  // To re-check for the conditions based on the new sharp and pinger values we send it back to check.
  goto check;
  }
  else if(( b > 15) && (a>15))
  {
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    delay(1000);
    right();
    sharp();
    pinger();
    goto check;
  }
 else if((a < 15) && ( b < 16))
 {
    left();
    sharp();
    pinger();
    goto check;
 }
 sharp();
 pinger();
}



