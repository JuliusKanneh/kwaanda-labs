#define DO_PIN 2
#define LED_PIN 4

void setup() {
  // Initialize the Serial to communicate with the Serial Monitor.
  Serial.begin(9600);
  // initialize the Arduino Nano's pin as an input
  pinMode(DO_PIN, INPUT);
  pinMode(LED_PIN, INPUT);

  Serial.println("Warming up the MQ2 sensor");
  delay(20000);
}

void loop() {
  int gasState = digitalRead(DO_PIN);
  Serial.println(gasState);

  if (gasState == HIGH){
    digitalWrite(LED_PIN, HIGH);
    Serial.println("The gas is NOT present");
  }else{
    digitalWrite(LED_PIN, LOW);
    Serial.println("The gas is Present");
  }
}
