#ifndef _EFFECT_RIPPLE_H_
#define _EFFECT_RIPPLE_H_

#include "../IEffect.h"

class LowPowerSparkle : public IEffect
{
public:
  static const int RIPPLE_COUNT = 12;

public:
  LowPowerSparkle(Adafruit_NeoPixel &leds);

  virtual void onEntry() override;
  virtual void onOperate() override;

protected:
  void ripple(int idx, int count);

protected:
  int m_ripplePosition;
  int m_ripples[RIPPLE_COUNT];

  int m_red[RIPPLE_COUNT];
  int m_green[RIPPLE_COUNT];
  int m_blue[RIPPLE_COUNT];
};

#endif
