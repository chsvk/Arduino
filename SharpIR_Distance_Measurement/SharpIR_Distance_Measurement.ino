

// Sharp IR GP2Y0A41SK0F Distance Test
// Sharp IR GP2Y0A41SK0F (4-30cm, analog)
#define sensor A0

void setup() {
  // start the serial port
  Serial.begin(9600); 
}

void loop() {
  
  // value from sensor * (5/1024)
  float volts = analogRead(sensor)*0.0048828125;  
  // worked out from datasheet graph
  int distance = 13*pow(volts, -1); 
  // slow down serial port 
  delay(1000); 
  
  if (distance <= 30){
    // print the distance
    Serial.println(distance);     
    }
}
