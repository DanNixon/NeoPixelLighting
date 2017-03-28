#include "IEffect.h"

IEffect::IEffect()
    : m_leds(nullptr)
{
}

IEffect::~IEffect()
{
}

void IEffect::setAllLEDs(uint32_t colour)
{
  for (size_t i = 0; i < m_leds->numPixels(); i++)
  {
    m_leds->setPixelColor(i, colour);
    m_leds->show();
    delay(5);
  }
}
