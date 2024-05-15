#define AO_PIN A5  // Arduino Nano's pin connected to AO pin of the MQ2 sensor

void setup() {
  // Initialize the Serial to communicate with the Serial Monitor.
  Serial.begin(9600);
  Serial.println("Warming up the MQ2 sensor");
  delay(20000);  // wait for the MQ2 to warm up
}

void loop() {
  int gasValue = analogRead(AO_PIN);

  Serial.print("MQ2 sensor AO value: ");
  Serial.println(gasValue);
  delay(500);
}
