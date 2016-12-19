#include "StaticColour.h"

#include <inttypes.h>

StaticColour::StaticColour(Adafruit_NeoPixel &leds, uint8_t red, uint8_t green, uint8_t blue)
    : IEffect(leds)
    , m_colour(Adafruit_NeoPixel::Color(red, green, blue))
{
}

void StaticColour::onEntry()
{
  setAllLEDs(m_colour);
}
