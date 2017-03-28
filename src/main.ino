#include <EEPROM.h>
#include <NeoPixelLighting.h>

NeoPixelLighting lighting;

#include "setup.h"

void setup()
{
#ifdef SERIAL_BAUD
  Serial.begin(SERIAL_BAUD);
#endif

  lighting.begin(LED_PIN, LED_COUNT);

  led_setup();

#ifdef SERIAL_BAUD
  lighting.addController(new SerialController(Serial));
#endif
}

void loop()
{
  lighting.update();
}
