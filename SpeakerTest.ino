#include <MeOrion.h>
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Wire.h>

MeUltrasonicSensor ultraSensor(PORT_6);

void setup() {
  Serial.begin(9600);
}

void loop() {
  float distance = ultraSensor.distanceCm() * 0.393701; // cm to inch conversion

  if (distance >= 400.0) {
    Serial.println("No object detected.");
  } else {
    Serial.print("Object detected! Distance: ");
    Serial.print(distance, 2); // print 2 decimal places
    Serial.println(" inch");
  }

  delay(100);
}
