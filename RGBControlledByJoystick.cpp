#include <MeOrion.h>
#include <Wire.h>
#include <SoftwareSerial.h>


MeRGBLed led(PORT_3);

MeJoystick joystick(PORT_6);

int x = 0; //Variable for joysticks X value 
int y = 0; //Variable for joysticks X value 


int ledCount = 15;
float j,f,k;


void setup()
{
  //Initialize Joystick serial communication at 9600 bps
  Serial.begin(9600);

  /*
  led.setNumber(ledCount);
  randomSeed(analogRead(A0)); // seeds random() using a floating pin
  */

}
void loop()
{
  //read both x and y values of joystick 
  x = joystick.readX();
  y = joystick.readY();

  //print the results of serial monitor
  Serial.print("JoystickX = ");
  Serial.print(x);
  Serial.print("\tJoystickY = ");
  Serial.print(y);
  //wait 100 milliseconds before the next loop
  delay(100);

  // ---- NEW: control LED based on joystick ----
  
  int red = map(x, 0, 1023, 0, 255);   // map x to red brightness
  int green = map(y, 0, 1023, 0, 255); // map y to green brightness
  int blue = 255 - ((red + green) / 2); // just a fun inverse for blue

  // Only one LED (t=0) to keep it simple for now
  led.setColorAt(0, red, green, blue);
  led.show();

  delay(100);
}
