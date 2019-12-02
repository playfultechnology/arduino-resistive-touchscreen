/**
 * Resistive Touchscreen Example
 * (c) 2019 Playful Technology
 */

// CONSTANTS
// UR, LR, UL, LL corner pins
const byte cornerPins[] = {2, 3, 4, 5};
// Central sensor pin
const byte sensePin = A0;

// GLOBALS
// Last sensed values
int x, y;

void setup() {
  // Configure corner pins as outputs
  for(int i=0; i<4; i++){
    pinMode(cornerPins[i], OUTPUT);
  }
  // Start serial connection to monitor output
  Serial.begin(9600);
}

void loop() {
  // Set the left-hand corner pins LOW and the right-hand corner pins HIGH
  digitalWrite(cornerPins[0], HIGH);
  digitalWrite(cornerPins[1], HIGH);
  digitalWrite(cornerPins[2], LOW);
  digitalWrite(cornerPins[3], LOW);
  // Read the sensor value in the x gradient
  x = analogRead(sensePin);

  // Set the bottom corner pins LOW and the top corner pins HIGH
  digitalWrite(cornerPins[0], HIGH);
  digitalWrite(cornerPins[1], LOW);
  digitalWrite(cornerPins[2], HIGH);
  digitalWrite(cornerPins[3], LOW);
  // Read the sensor value in the y gradient
  y = analogRead(sensePin);

  // Display the co-ordinate value obtained
  Serial.print(x);  
  Serial.print(",");
  Serial.println(y);
}
