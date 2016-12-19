#ifndef _EFFECT_RIPPLE_H_
#define _EFFECT_RIPPLE_H_

#include "../IEffect.h"

class LowPowerSparkle : public IEffect
{
public:
  static const int RIPPLE_COUNT = 12;

public:
  LowPowerSparkle(uint16_t delay = 40);

  virtual void onEntry() override;
  virtual void onOperate() override;

protected:
  void ripple(int idx, int count);

protected:
  const uint16_t m_frameDelay;

  uint16_t m_ripplePosition;
  uint16_t m_ripples[RIPPLE_COUNT];

  uint8_t m_red[RIPPLE_COUNT];
  uint8_t m_green[RIPPLE_COUNT];
  uint8_t m_blue[RIPPLE_COUNT];
};

#endif
