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
  x = joystick.readX();
  y = joystick.readY();

  Serial.print("JoystickX = ");
  Serial.print(x);
  Serial.print("\tJoystickY = ");
  Serial.println(y);

  // Map joystick X axis to a color hue
  float hue = map(x, 0, 1023, 0, 1000) / 1000.0; // hue 0.0 to 1.0

  uint8_t r, g, b;
  HSVtoRGB(hue, r, g, b);  // Convert hue to RGB colors

  led.setColorAt(0, r, g, b);
  led.show();

  delay(50); // smoothness
}


void HSVtoRGB(float h, uint8_t &r, uint8_t &g, uint8_t &b) {
  float s = 1.0;
  float v = 1.0;
  int i = int(h * 6);
  float f = h * 6 - i;
  float p = v * (1 - s);
  float q = v * (1 - f * s);
  float t = v * (1 - (1 - f) * s);

  switch (i % 6) {
    case 0: r = 255 * v; g = 255 * t; b = 255 * p; break;
    case 1: r = 255 * q; g = 255 * v; b = 255 * p; break;
    case 2: r = 255 * p; g = 255 * v; b = 255 * t; break;
    case 3: r = 255 * p; g = 255 * q; b = 255 * v; break;
    case 4: r = 255 * t; g = 255 * p; b = 255 * v; break;
    case 5: r = 255 * v; g = 255 * p; b = 255 * q; break;
  }
}
