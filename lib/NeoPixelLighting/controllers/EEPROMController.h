#ifndef _EEPROMCONTROLLER_H_
#define _EEPROMCONTROLLER_H_

#include <inttypes.h>

#include "../IController.h"

class EEPROMController : public IController
{
public:
  EEPROMController(uint8_t address = 0, bool incrementOnPower = true);

  virtual bool testTransfer(uint8_t *nextEffectIdx) override;

protected:
  const uint8_t m_address;
  bool m_executed;
  bool m_incrementOnPower;
};

#endif
