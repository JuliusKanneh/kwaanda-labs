#include <Servo.h>

const int servoPin = 2;
const int fanPin = 4;
Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);

  // pinMode(servoPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  // Turn on fan for 5 seconds
  digialWrite(fanPin, HIGH);
  delay(5000);
  digialWrite(fanPin, LOW);

  // Rotate fan to 180 degree
  pos = 180;
  myservo.write(pos);
  delay(15);

  // Turn on fan for 5 seconds
  digialWrite(fanPin, HIGH);
  delay(5000);
  digialWrite(fanPin, LOW);

  // Rotate fan to 360(0) degree
  pos = 360;
  myservo.write(pos);
  delay(15);

  delay(60000); //wait for 1minute before repeating the entire process. 
}
