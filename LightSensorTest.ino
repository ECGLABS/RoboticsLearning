#include <MeOrion.h>
#include <Wire.h>
#include <SoftwareSerial.h>

MePotentiometer potentiometer(PORT_6);

int val = 0;
//variable for light sensor's value

void setup()
{
  //initialize serial communications at 9600bps
  Serial.begin(9600);
}

void loop()
{
  //read the lightsensor value
  val = potentiometer.read();

  //print the results to the serial monitor
  Serial.print("Potentionmeter = ");
  Serial.println(val);
  //wait 100 milliseconds before the next loop
  delay(100);
}