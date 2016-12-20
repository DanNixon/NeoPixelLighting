#include "EEPROMController.h"

#include <EEPROM.h>
#include "../NeoPixelLighting.h"

EEPROMController::EEPROMController(uint8_t address, bool incrementOnPower)
    : IController()
    , m_address(address)
    , m_executed(false)
    , m_incrementOnPower(incrementOnPower)
{
}

bool EEPROMController::testTransfer(uint8_t *nextEffectIdx)
{
  if (!m_executed)
  {
    uint8_t idx = EEPROM.read(m_address);

    if (m_incrementOnPower)
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
