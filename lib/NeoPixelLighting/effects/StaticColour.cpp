#include "StaticColour.h"

#include <inttypes.h>

StaticColour::StaticColour(uint8_t red, uint8_t green, uint8_t blue)
    : IEffect()
    , m_colour(Adafruit_NeoPixel::Color(red, green, blue))
{
}

void StaticColour::onEntry()
{
  setAllLEDs(m_colour);
}
