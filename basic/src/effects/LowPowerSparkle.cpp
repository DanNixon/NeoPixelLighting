#include "LowPowerSparkle.h"

LowPowerSparkle::LowPowerSparkle(Adafruit_NeoPixel &leds)
    : IEffect(leds)
{
}

void LowPowerSparkle::onEntry()
{
  /* m_red = {255, 127, 0, 0, 0, 127, 255, 127, 0, 0, 0, 127}; */
  /* m_green = {0, 127, 255, 127, 0, 0, 0, 127, 255, 127, 0, 0}; */
  /* m_blue = {0, 0, 0, 127, 255, 127, 0, 0, 0, 127, 255, 127}; */
}

void LowPowerSparkle::onOperate()
{
  m_ripples[m_ripplePosition] =
      random(-RIPPLE_COUNT, m_leds.numPixels() + RIPPLE_COUNT - 1);

  m_leds.clear();

  for (size_t i = 0; i < RIPPLE_COUNT; i++)
    ripple(i, (m_ripplePosition + i) % RIPPLE_COUNT);

  m_leds.show();

  m_ripplePosition = (m_ripplePosition + 1) % RIPPLE_COUNT;
  delay(40);
}

void LowPowerSparkle::ripple(int idx, int count)
{
  int brightnessDivider = count;
  uint32_t colour = Adafruit_NeoPixel::Color(m_red[idx] / brightnessDivider,
                                             m_green[idx] / brightnessDivider,
                                             m_blue[idx] / brightnessDivider);

  if ((m_ripples[idx] + count) < m_leds.numPixels())
    m_leds.setPixelColor(m_ripples[idx] + count, colour);
  if ((m_ripples[idx] - count) >= 0)
    m_leds.setPixelColor(m_ripples[idx] - count, colour);
}
