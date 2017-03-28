#include "StaticColourArray.h"

#include <inttypes.h>

StaticColourArray::StaticColourArray(size_t size)
    : IEffect()
    , m_size(size)
    , m_colours(new uint32_t[size])
{
}

StaticColourArray::~StaticColourArray()
{
  delete[] m_colours;
}

void StaticColourArray::onEntry()
{
  size_t count = min(m_leds->numPixels(), m_size);

  for (size_t i = 0; i < count; i++)
  {
    m_leds->setPixelColor(i, m_colours[i]);
    m_leds->show();
    delay(5);
  }
}

void StaticColourArray::setColour(size_t i, uint8_t red, uint8_t green,
                                  uint8_t blue)
{
  if (i > m_size)
    return;

  m_colours[i] = Adafruit_NeoPixel::Color(red, green, blue);
}
