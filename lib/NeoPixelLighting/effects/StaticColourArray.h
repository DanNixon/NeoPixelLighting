#pragma once

#include "../IEffect.h"

class StaticColourArray : public IEffect
{
public:
  StaticColourArray(size_t size);
  virtual ~StaticColourArray();

  virtual void onEntry() override;

  void setColour(size_t i, uint8_t red, uint8_t green, uint8_t blue);

protected:
  size_t m_size;
  uint32_t *m_colours;
};
