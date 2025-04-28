#include <MeOrion.h>
#include <Wire.h>
#include <SoftwareSerial.h>

MeJoystick joystick(PORT_6);

int x = 0; //Variable for joysticks X value 
int y = 0; //Variable for joysticks X value 


void setup()
{
  //Initialize Joystick serial communication at 9600 bps
  Serial.begin(9600);

}
void loop()
{
  //read both x and y values of joystick 
  x = joystick.readX();
  y = joystick.readY();

  //print the results of serial monitor
  Serial.print("JoystickX = ");
  Serial.print(x);
  Serial.print("/tJoystickY = ");
  Serial.print(y);
  //wait 100 milliseconds before the next loop
  delay(100);

}

