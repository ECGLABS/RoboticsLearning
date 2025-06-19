#include <MeOrion.h>
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Wire.h>

MeBuzzer buzzer;
MeUltrasonicSensor ultraSensor(PORT_6);

int pushupCount = 0;
bool downDetected = false;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int distance = ultraSensor.distanceCm();

  // Go down phase (close to sensor)
if (distance < 20 && !downDetected) {
  downDetected = true;
  buzzer.tone(1000, 100);
}

if (distance > 35 && downDetected) {
  pushupCount++;
  downDetected = false;
  Serial.print("Push-ups: ");
  Serial.println(pushupCount);
}


  delay(100); // Minimum delay between checks
}
