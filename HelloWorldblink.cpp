void setup() {
  pinMode(13, OUTPUT);   // Set built-in LED pin as output
}

void loop() {
  digitalWrite(13, HIGH); // LED on
  delay(1000);            // Wait 1 second
  digitalWrite(13, LOW);  // LED off
  delay(1000);            // Wait 1 second
}
