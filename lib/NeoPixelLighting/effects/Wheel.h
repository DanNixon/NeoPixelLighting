#ifndef _EFFECTS_WHEEL_H_
#define _EFFECTS_WHEEL_H_

#include "../IEffect.h"

class Wheel : public IEffect
{
public:
  Wheel();

  virtual void onOperate() override;
};

#endif
