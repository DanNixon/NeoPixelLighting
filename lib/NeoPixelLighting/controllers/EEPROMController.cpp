#include "EEPROMController.h"

#include <EEPROM.h>
#include "../NeoPixelLighting.h"

EEPROMController::EEPROMController(uint8_t address)
    : IController()
    , m_address(address)
    , m_executed(false)
{
}

bool EEPROMController::testTransfer(uint8_t *nextEffectIdx)
{
  if (!m_executed)
  {
    uint8_t idx = EEPROM.read(m_address);
    idx++;
    if (idx >= m_host->getNumEffects())
      idx = 0;
    EEPROM.write(m_address, idx);

    *nextEffectIdx = idx;
    m_executed = true;
    return true;
  }

  return false;
}
