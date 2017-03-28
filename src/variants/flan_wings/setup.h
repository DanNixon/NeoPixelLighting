#include <effects/LowPowerSparkle.h>
#include <effects/StaticColour.h>
#include <effects/Wheel.h>

#include <controllers/EEPROMController.h>
#include <controllers/SerialController.h>

void led_setup()
{
  lighting.addEffect(new LowPowerSparkle(120));
  lighting.addEffect(new Wheel());
  lighting.addEffect(new StaticColour(255, 0, 0));
  lighting.addEffect(new StaticColour(0, 255, 0));
  lighting.addEffect(new StaticColour(0, 0, 255));
  lighting.addEffect(new StaticColour(255, 255, 255));

  lighting.addController(new EEPROMController(true));
}
