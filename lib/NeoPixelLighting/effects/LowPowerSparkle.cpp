#include "LowPowerSparkle.h"

LowPowerSparkle::LowPowerSparkle(uint16_t delay)
    : IEffect()
    , m_frameDelay(delay)
{
}

void LowPowerSparkle::onEntry()
{
  memset(m_red, 0, RIPPLE_COUNT);
  memset(m_green, 0, RIPPLE_COUNT);
  memset(m_blue, 0, RIPPLE_COUNT);

  m_red[0] = 255;
  m_red[1] = 127;
  m_red[5] = 127;
  m_red[6] = 255;
  m_red[7] = 127;
  m_red[11] = 127;

  m_green[1] = 127;
  m_green[2] = 255;
  m_green[3] = 127;
  m_green[7] = 127;
  m_green[8] = 255;
  m_green[9] = 127;

  m_blue[3] = 127;
  m_blue[4] = 255;
  m_blue[5] = 127;
  m_blue[9] = 127;
  m_blue[10] = 255;
  m_blue[11] = 127;
}

void LowPowerSparkle::onOperate()
{
  m_ripples[m_ripplePosition] =
      random(-RIPPLE_COUNT, m_leds->numPixels() + RIPPLE_COUNT - 1);

  m_leds->clear();

  for (uint16_t i = 0; i < RIPPLE_COUNT; i++)
    ripple(i, (m_ripplePosition + i) % RIPPLE_COUNT);

  m_leds->show();

  m_ripplePosition = (m_ripplePosition + 1) % RIPPLE_COUNT;
  delay(m_frameDelay);
}

void LowPowerSparkle::ripple(int idx, int count)
{
  int brightnessDivider = count;
  uint32_t colour = Adafruit_NeoPixel::Color(
      brightnessDivider == 0 ? 255 : m_red[idx] / brightnessDivider,
      brightnessDivider == 0 ? 255 : m_green[idx] / brightnessDivider,
      brightnessDivider == 0 ? 255 : m_blue[idx] / brightnessDivider);

  if ((m_ripples[idx] + count) < m_leds->numPixels())
    m_leds->setPixelColor(m_ripples[idx] + count, colour);
  if ((m_ripples[idx] - count) >= 0)
    m_leds->setPixelColor(m_ripples[idx] - count, colour);
}


/* TODO: Use Alistair's new code: */
/* // An array to hold the starting posiition of each ripple */
/* int ripples[RIPPLECOUNT]; */
/* // Pointer to the next ripple to move */
/* int ripplePos = 0; */
/* void loop() */
/* { */
/*   // Move the next ripple to a new positon */
/*   ripples[ripplePos] = random(0, LEDCOUNT - 1); */
/*   // Clear the strip */
/*   strip.clear(); */
/*   // Loop thought each ripple (oldest and darkest first) and add it to the strip */
/*   int j = 0; */
/*   for (int i = 0; i < RIPPLECOUNT; i++) */
/*   { */
/*     j = (ripplePos + i + 1) % RIPPLECOUNT; */
/*     rippleOne(ripples[j], (RIPPLECOUNT - i), red[j], green[j], blue[j]); */
/*   } */
/*   // Push the new colours to the strip */
/*   strip.show(); */
/*   // Update the pointer for the next loop */
/*   ripplePos = (ripplePos + 1) % RIPPLECOUNT; */
/*   // Wait a frame */
/*   delay(40); */
/* } */
/* void rippleOne(int inStart, int inCount, int inRed, int inGreen, int inBlue) */
/* { */
/*   strip.setPixelColor( */
/*       (inStart + inCount) % LEDCOUNT, */
/*       strip.Color(inRed / inCount, inGreen / inCount, inBlue / inCount)); */
/*   strip.setPixelColor( */
/*       (inStart + LEDCOUNT - inCount) % LEDCOUNT, */
/*       strip.Color(inRed / inCount, inGreen / inCount, inBlue / inCount)); */
/* } */
