
// Block Width measuring and classification.
// Written By Dheeraj Allamaneni and Chatti Vamshi Krishna.
// This work is licensed under a Creative Commons Attribution-NonCommercial 4.0 International License.
// Adaptations of this work are allowed.
// Commercial usage of this work is restricted.
// Fork updations to this code to the main github repository. *(GITHUB LINKS BELOW)*
// Any feedback or improvements are appreciated.


//Initializing the Pin Numbers that we will be using on the arduino board
#define trigPin 10
#define echoPin 11


// Creating variables to store the values of distance and duration
long distance,duration;
int i;


//Setting Up the pins that we plan to use
void setup() {
  //Initializing the serial monitor
  Serial.begin (9600);
  //Setting the mode of use for the pins that we declared
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}


//Creating a function to check the distance from the block to the Ultrasonic Sensor
long check_distance()
{
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  delay(10);
  return distance;
}

// This was written for testing purposes can be eliminated or optimized.
long pingpong() {
  distance = check_distance();
    Serial.print(distance);
    Serial.println(" cm");
   // Returning the distance or width of the block measured
  return distance;
  delay(2);
}

// Determining the width of the block from the above function check_distance()
void loop() {
  
  long dist=pingpong();
  i=0;
  for(i;dist<=25;i++){
    dist=pingpong();
    
    }
if(i>5){
  Serial.println(i);
}

}




// GITHUB LINKS OF THE AUTHORS
//
