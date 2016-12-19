#include "IEffect.h"

IEffect::IEffect(Adafruit_NeoPixel &leds)
    : m_leds(leds)
{
}

void IEffect::setAllLEDs(uint32_t colour)
{
  for (size_t i = 0; i < m_leds.numPixels(); i++)
    m_leds.setPixelColor(i, colour);
}
