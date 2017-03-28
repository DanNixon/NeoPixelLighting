#include <effects/StaticColour.h>
#include <effects/Wheel.h>
#include <effects/LowPowerSparkle.h>
#include <controllers/EEPROMController.h>
#include <controllers/SerialController.h>

void led_setup()
{
  lighting.addEffect(new LowPowerSparkle(120));         // Flash
  lighting.addEffect(new Wheel());                      // Smooth
  lighting.addEffect(new StaticColour(255, 0, 0));      // Red
  lighting.addEffect(new StaticColour(0, 255, 0));      // Green
  lighting.addEffect(new StaticColour(0, 0, 255));      // Blue
  lighting.addEffect(new StaticColour(255, 255, 255));  // White

  lighting.addController(new EEPROMController(true));
}
