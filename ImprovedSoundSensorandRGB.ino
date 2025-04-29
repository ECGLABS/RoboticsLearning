 #include <MeOrion.h>
#include <Wire.h>
#include <SoftwareSerial.h>

MeSoundSensor SoundSensor(PORT_6);
MeRGBLed led(PORT_3);

int analog_val = 0;
//variable for the SoundSensor's analog result
int k=0;

void setup()
{
  //initialize serial communications at 9600bps
  led.setNumber(4);
}

void loop()
{
  //read the SoundSensor's result
  analog_val = SoundSensor.strength();
  k=abs(analog_val-486);

if(k > 5 && k < 480) {
  for(int t = 0; t < 4; t++)
    led.setColorAt(t, k, k, k);
  led.show();
  delay(50);
} else {
  for(int t = 0; t < 4; t++)
    led.setColorAt(t, 0, 0, 0);
  led.show();
}
}