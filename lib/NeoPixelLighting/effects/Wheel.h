#pragma once

#include "../IEffect.h"

class Wheel : public IEffect
{
public:
  Wheel();

  virtual void onOperate() override;

private:
  uint16_t m_wheelPos;
};
