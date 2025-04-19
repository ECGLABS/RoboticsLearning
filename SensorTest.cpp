#include <MeOrion.h>
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Wire.h>

MeBuzzer buzzer;
MeUltrasonicSensor ultraSensor(PORT_6);
void setup() 
{
  // initialize serial communications at 9600 bps
Serial.begin(9600);
}

void loop() {
  int distance = ultraSensor.distanceCm();
  Serial.print("Distance: ");
  Serial.print(ultraSensor.distanceCm());
//print the measure centimeter of distance
  Serial.print("inch ");

  if (distance < 10) { // if an object is closer than 10 cm
    buzzer.tone(1000, 100); // beep at 1000Hz for 100ms
  }
delay(100);
//the minimal measure interval is 100 milliseconds
}





