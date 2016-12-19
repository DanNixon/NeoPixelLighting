#ifndef _EFFECTS_STATICCOLOUR_H_
#define _EFFECTS_STATICCOLOUR_H_

#include "../IEffect.h"

class StaticColour : public IEffect
{
public:
  StaticColour(uint8_t red, uint8_t green, uint8_t blue);

  virtual void onEntry() override;

protected:
  uint32_t m_colour;
};

#endif
