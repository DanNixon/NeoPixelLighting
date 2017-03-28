#pragma once

#include <inttypes.h>

#include "../IController.h"

class EEPROMController : public IController
{
public:
  static const uint8_t EFFECT_ADDRESS = 0;
  static const uint8_t BRIGHTNESS_ADDRESS = 1;

public:
  EEPROMController(bool incrementOnPower = true);

  virtual void update() override;
  virtual void onSetBrightness(uint8_t brightness) override;
  virtual void onSetEffect(uint8_t effectIdx) override;

protected:
  bool m_executed;
  bool m_incrementOnPower;
};
