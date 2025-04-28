#include <MeOrion.h>
#include <Wire.h>
#include <SoftwareSerial.h>

MeRGBLed led(PORT_3);

int ledCount = 15;
float j,f,k;
void setup()
{
  led.setNumber(ledCount);
  randomSeed(analogRead(A0)); // seeds random() using a floating pin
}
void loop()
{
  color_loop();
}

void color_loop() {
  for (uint8_t t = 0; t < ledCount; t++) {
    uint8_t red = 64 * (1 + sin(t / 2.0 + j / 4.0));
    uint8_t green = 64 * (1 + sin(t / 1.0 + f / 9.0 + 2.1));
    uint8_t blue = 64 * (1 + sin(t / 3.0 + k / 14.0 + 4.2));

    if (random(2) == 1) {
      led.setColorAt(t, red, green, blue); // turn ON with color
    } else {
      led.setColorAt(t, 0, 0, 0);           // turn OFF
    }
  }
  led.show();

  j += (random(16) / 10.0) / 6.0;
  f += (random(16) / 10.0) / 6.0;
  k += (random(16) / 10.0) / 6.0;
}
