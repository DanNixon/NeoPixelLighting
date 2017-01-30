#include <EEPROM.h>
#include <IRLibAll.h>

#include <NeoPixelLighting.h>
#include <IEffect.h>
#include <effects/StaticColour.h>
#include <effects/Wheel.h>
#include <effects/LowPowerSparkle.h>
#include <controllers/EEPROMController.h>
#include <controllers/SerialController.h>
#include <controllers/IRController.h>

#define SERIAL_BAUD 9600

NeoPixelLighting lighting;

void setup()
{
  IRControllerRemote remote1 = {NEC, {0xFFE01F, 0xFF609F, 0xFF20DF, 0xFFA05F, 0xFFF00F, 0xFFE817, 0xFFD827, 0xFFC837, 0xFF906F, 0xFF10EF, 0xFF50AF, 0xFFD02F, 0xFFB04F, 0xFF30CF, 0xFF708F, 0xFFA857, 0xFF28D7, 0xFF6897, 0xFF9867, 0xFF18E7, 0xFF58A7, 0xFF8877, 0xFF08F7, 0xFF48B7}};
  IRControllerRemote remote2 = {NEC, {0xF7C03F, 0xF740BF, 0xF7807F, 0xF700FF, 0xF7D02F, 0xF7F00F, 0xF7C837, 0xF7E817, 0xF720DF, 0xF7A05F, 0xF7609F, 0xF7E01F, 0xF710EF, 0xF7906F, 0xF750AF, 0xF730CF, 0xF7B04F, 0xF7708F, 0xF708F7, 0xF78877, 0xF748B7, 0xF728D7, 0xF7A857, 0xF76897}};

#ifdef SERIAL_BAUD
  Serial.begin(SERIAL_BAUD);
#endif

  lighting.begin(7, 35);

  lighting.addEffect(new LowPowerSparkle(120));         // Flash
  lighting.addEffect(new IEffect());                    // Strobe
  lighting.addEffect(new IEffect());                    // Fade
  lighting.addEffect(new Wheel());                      // Smooth
  lighting.addEffect(new StaticColour(255, 0, 0));      // Red
  lighting.addEffect(new StaticColour(0, 255, 0));      // Green
  lighting.addEffect(new StaticColour(0, 0, 255));      // Blue
  lighting.addEffect(new StaticColour(255, 255, 255));  // White

  /* TODO */
  lighting.addEffect(new StaticColour(0, 0, 0));        // Colour 1
  lighting.addEffect(new StaticColour(0, 0, 0));        // Colour 2
  lighting.addEffect(new StaticColour(0, 0, 0));        // Colour 3
  lighting.addEffect(new StaticColour(0, 0, 0));        // Colour 4
  lighting.addEffect(new StaticColour(0, 0, 0));        // Colour 5
  lighting.addEffect(new StaticColour(0, 0, 0));        // Colour 6
  lighting.addEffect(new StaticColour(0, 0, 0));        // Colour 7
  lighting.addEffect(new StaticColour(0, 0, 0));        // Colour 8
  lighting.addEffect(new StaticColour(0, 0, 0));        // Colour 9
  lighting.addEffect(new StaticColour(0, 0, 0));        // Colour 10
  lighting.addEffect(new StaticColour(0, 0, 0));        // Colour 11
  lighting.addEffect(new StaticColour(0, 0, 0));        // Colour 12

  lighting.addController(new EEPROMController(false));
  lighting.addController(new IRController(2, remote2));
#ifdef SERIAL_BAUD
  lighting.addController(new SerialController(Serial));
#endif
}

void loop()
{
  lighting.update();
}
