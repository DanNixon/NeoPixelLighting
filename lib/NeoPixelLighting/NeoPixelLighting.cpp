#include "NeoPixelLighting.h"

NeoPixelLighting::NeoPixelLighting()
    : m_leds(nullptr)
    , m_numEffects(0)
    , m_numControllers(0)
    , m_currentEffectIdx(0)
{
  uint8_t i;

  for (i = 0; i < MAX_NUM_EFFECTS; i++)
    m_effects[i] = nullptr;

  for (i = 0; i < MAX_NUM_CONTROLLERS; i++)
    m_controllers[i] = nullptr;
}

void NeoPixelLighting::begin(uint8_t pin, uint16_t numPixels)
{
  m_leds = new Adafruit_NeoPixel(numPixels, pin, NEO_GRB + NEO_KHZ800);
  m_leds->begin();
  m_leds->show();
}

void NeoPixelLighting::update()
{
  m_effects[m_currentEffectIdx]->onOperate();

  uint8_t nextEffect;
  for (uint8_t i = 0; i < m_numControllers; i++)
  {
    if (m_controllers[i]->testTransfer(&nextEffect))
    {
      switchToEffect(nextEffect);
      return;
    }
  }
}

bool NeoPixelLighting::addEffect(IEffect *effect)
{
  if (m_numEffects >= MAX_NUM_EFFECTS)
    return false;

  effect->m_leds = m_leds;
  m_effects[m_numEffects++] = effect;
  return true;
}

uint8_t NeoPixelLighting::getEffectIdx(IEffect *effect)
{
  uint8_t i;
  for (i = 0; i < m_numEffects; i++)
  {
    if (m_effects[i] == effect)
      break;
  }

  return i;
}

bool NeoPixelLighting::addController(IController *controller)
{
  if (m_numControllers >= MAX_NUM_CONTROLLERS)
    return false;

  controller->m_host = this;
  m_controllers[m_numControllers++] = controller;
  return true;
}

void NeoPixelLighting::setBrightness(uint8_t brightness)
{
  m_leds->setBrightness(brightness);
  m_leds->show();
}

void NeoPixelLighting::switchToEffect(uint8_t effectIdx)
{
  m_effects[m_currentEffectIdx]->onExit();
  m_currentEffectIdx = effectIdx;
  m_effects[m_currentEffectIdx]->onEntry();
}
