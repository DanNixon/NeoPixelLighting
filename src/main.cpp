#include <EEPROM.h>

#include <NeoPixelLighting.h>
#include <IEffect.h>
#include <effects/StaticColour.h>
#include <effects/Wheel.h>
#include <effects/LowPowerSparkle.h>
#include <controllers/EEPROMController.h>

#define SERIAL_BAUD 115200

NeoPixelLighting lighting;

void setup()
{
#ifdef SERIAL_BAUD
  Serial.begin(SERIAL_BAUD);
#endif

  lighting.begin(7, 35);
  lighting.setBrightness(50);

  lighting.addEffect(new IEffect());
  lighting.addEffect(new StaticColour(255, 0, 0));
  lighting.addEffect(new StaticColour(0, 255, 0));
  lighting.addEffect(new StaticColour(0, 0, 255));
  lighting.addEffect(new StaticColour(255, 255, 0));
  lighting.addEffect(new StaticColour(0, 255, 255));
  lighting.addEffect(new StaticColour(255, 0, 255));
  lighting.addEffect(new StaticColour(255, 255, 255));
  lighting.addEffect(new Wheel());
  lighting.addEffect(new LowPowerSparkle(120));

  lighting.addController(new EEPROMController());
}

void loop()
{
  lighting.update();
}
