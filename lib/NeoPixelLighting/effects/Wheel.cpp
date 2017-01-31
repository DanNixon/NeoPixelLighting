#include "Wheel.h"

#include <inttypes.h>

uint32_t wheel(byte wheel_pos)
{
  if (wheel_pos < 85)
  {
    return Adafruit_NeoPixel::Color(wheel_pos * 3, 255 - wheel_pos * 3, 0);
  }
  else if (wheel_pos < 170)
  {
    wheel_pos -= 85;
    return Adafruit_NeoPixel::Color(255 - wheel_pos * 3, 0, wheel_pos * 3);
  }
  else
  {
    wheel_pos -= 170;
    return Adafruit_NeoPixel::Color(0, wheel_pos * 3, 255 - wheel_pos * 3);
  }
}

Wheel::Wheel()
    : IEffect()
    , m_wheelPos(0)
{
}

void Wheel::onOperate()
{
  m_wheelPos++;
  if (m_wheelPos > 255)
    m_wheelPos = 0;

  for (uint16_t i = 0; i < m_leds->numPixels(); i++)
    m_leds->setPixelColor(i, wheel((i + m_wheelPos) & 255));
  m_leds->show();
  delay(25);
}
