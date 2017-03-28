#include <effects/LowPowerSparkle.h>
#include <effects/StaticColour.h>
#include <effects/StaticColourArray.h>
#include <effects/Wheel.h>

#include <controllers/EEPROMController.h>
#include <controllers/SerialController.h>

void led_setup()
{
  StaticColourArray *ca = new StaticColourArray(LED_COUNT);

  for (size_t i = 0; i < LED_COUNT; i += 7)
  {
    ca->setColour(i + 0, 64, 176, 255); // Light blue
    ca->setColour(i + 1, 0, 0, 255);    // Blue
    ca->setColour(i + 2, 100, 16, 180); // PUrple
    ca->setColour(i + 3, 255, 64, 64);  // Pink
    ca->setColour(i + 4, 255, 100, 0);  // Orange
    ca->setColour(i + 5, 255, 225, 24); // Yellow
    ca->setColour(i + 6, 50, 255, 50);  // Light green
  }

  lighting.addEffect(ca);

  /* lighting.addEffect(new LowPowerSparkle(120)); */
  /* lighting.addEffect(new Wheel()); */
  /* lighting.addEffect(new StaticColour(255, 0, 0)); */
  /* lighting.addEffect(new StaticColour(0, 255, 0)); */
  /* lighting.addEffect(new StaticColour(0, 0, 255)); */
  /* lighting.addEffect(new StaticColour(255, 255, 255)); */

  lighting.addController(new EEPROMController(true));
}
