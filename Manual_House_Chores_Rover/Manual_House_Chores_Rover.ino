// Manual House Chores Rover


// Initializing the motors for the robot
#define lm1  A0
#define lm2  A1
#define rm1 A2
#define rm2 A3
#define lu 2
#define ld 3
#define hi 5
#define ho 6


const int ledPin = 13;      // the pin that the LED is attached to
  byte serialA;
void setup()
{
  // initialize the serial communication:
  Serial.begin(9600);
  //baud rate - make sure it matches that of the module you got:
  // initialize the ledPin as an output:
  pinMode(ledPin, OUTPUT);
}

void loop() {


// Checking the serial values that are sent from the bluetooth connection.
// The recieved values are processed and interpreted into different conditions for the rover.
if (Serial.available() > 0) {serialA = Serial.read();Serial.println(serialA);}

   // Different conditions / actions for the rover to perform based on its recieving value.
      switch (serialA) {
    case 'F':
      digitalWrite(lm1, HIGH);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, HIGH);
      digitalWrite(rm2, LOW);
      delay(10);
      break;
    case 'B':
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, HIGH);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, HIGH);
      delay(10);
      break;
    case 'L':
      digitalWrite(rm1, HIGH);
      digitalWrite(rm2, LOW);
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, HIGH);
      delay(10);
      break;
    case 'R':
      digitalWrite(lm1, HIGH);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, HIGH);
      delay(10);
      break;
    case 'G':
      digitalWrite(lm1, HIGH);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, HIGH);
      digitalWrite(rm2, LOW);
      delay(10);
      break;
    case 'I':
      digitalWrite(lm1, HIGH);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, HIGH);
      digitalWrite(rm2, LOW);
      delay(10);
      break;
    case 'S':
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(10);
      break;
     
    case 'H':
      digitalWrite(lm1, HIGH);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, HIGH);
      delay(10);
      break;
     case 'J':
      digitalWrite(lm1, HIGH);
      digitalWrite(lm2, LOW);
      digitalWrite(lm1, HIGH);
      digitalWrite(lm1, HIGH);
      delay(10);
      break;

     case 'W':
      digitalWrite(lu, HIGH);
      digitalWrite(ld, LOW);
      delay(10);
      break;

     case 'w':
      digitalWrite(lu, LOW);
      digitalWrite(ld, HIGH);
      delay(10);
      break;

    case 'U':
      digitalWrite(hi, HIGH);
      digitalWrite(ho, LOW);
      delay(10);
      break;

    case 'u':
      digitalWrite(hi, LOW);
      digitalWrite(ho, HIGH);
      delay(10);
      break;


      break;

      default : 
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(lm1, LOW);
      digitalWrite(lm1, LOW);
      break;
  }

} 
