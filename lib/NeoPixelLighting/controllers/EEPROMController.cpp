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

void EEPROMController::update()
{
  if (!m_executed)
  {
    uint8_t brightness = EEPROM.read(m_address + 1);
    m_host->setBrightness(brightness);

    uint8_t idx = EEPROM.read(m_address);
    if (m_incrementOnPower)
      idx++;
    if (idx >= m_host->getNumEffects())
      idx = 0;
    m_host->switchToEffect(idx);

    m_executed = true;
  }
}

void EEPROMController::onSetBrightness(uint8_t brightness)
{
  EEPROM.write(m_address + 1, brightness);
}

void EEPROMController::onSetEffect(uint8_t effectIdx)
{
  EEPROM.write(m_address, effectIdx);
}
