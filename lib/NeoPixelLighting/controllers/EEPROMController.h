#ifndef _EEPROMCONTROLLER_H_
#define _EEPROMCONTROLLER_H_

#include <inttypes.h>

#include "../IController.h"

class EEPROMController : public IController
{
public:
  EEPROMController(uint8_t address = 0, bool incrementOnPower = true);

  virtual void update() override;
  virtual void onSetBrightness(uint8_t brightness) override;
  virtual void onSetEffect(uint8_t effectIdx) override;

protected:
  const uint8_t m_address;
  bool m_executed;
  bool m_incrementOnPower;
};

#endif
