#include "EEPROMController.h"

#include <EEPROM.h>
#include "../NeoPixelLighting.h"

EEPROMController::EEPROMController(bool incrementOnPower)
    : IController()
    , m_executed(false)
    , m_incrementOnPower(incrementOnPower)
{
}

void EEPROMController::update()
{
  if (!m_executed)
  {
    uint8_t brightness = EEPROM.read(BRIGHTNESS_ADDRESS);
    m_host->setBrightness(brightness);

    uint8_t idx = EEPROM.read(EFFECT_ADDRESS);
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
  EEPROM.write(BRIGHTNESS_ADDRESS, brightness);
}

void EEPROMController::onSetEffect(uint8_t effectIdx)
{
  EEPROM.write(EFFECT_ADDRESS, effectIdx);
}
