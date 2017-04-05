#include <EEPROM.h>
#include <NeoPixelLighting.h>
#include <controllers/SerialController.h>

NeoPixelLighting lighting;

#include "setup.h"

void setup()
{
#ifdef SERIAL_BAUD
  Serial.begin(SERIAL_BAUD);
  Serial.println("Hello");
#endif

  lighting.begin(LED_PIN, LED_COUNT);

  led_setup();

#ifdef SERIAL_BAUD
  lighting.addController(new SerialController(Serial));
#endif

  lighting.setBrightness(255);
  lighting.switchToEffect(0);
}

void loop()
{
  lighting.update();
}
