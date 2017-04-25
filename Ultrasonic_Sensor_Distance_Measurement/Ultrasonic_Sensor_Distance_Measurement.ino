

// Ping Sensor / Ultrasonic Sensor Test
#define trigPin 10
#define echoPin 11

long distance,duration,distance2,duration2;
void setup() {
  // intializing the serial monitor
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  distance = check_distance();
  // finding out the distance and printing it out to the serial monitor.
    Serial.print(distance);
    Serial.print("cm, ");
    Serial.println();
    delay(2);
} 

long check_distance()
{
  // Giving short pulses to the sensor to read the values and determine the distance of the object
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  // calculating the distance
  distance = (duration/2) / 29.1;
  delay(200);
  return distance;
}


