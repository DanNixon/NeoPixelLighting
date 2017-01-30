#ifndef _NEOPIXELLIGHTING_H_
#define _NEOPIXELLIGHTING_H_

#include <Adafruit_NeoPixel.h>

#include "IEffect.h"
#include "IController.h"

class NeoPixelLighting
{
public:
  static const uint8_t MAX_NUM_EFFECTS = 32;
  static const uint8_t MAX_NUM_CONTROLLERS = 8;

public:
  NeoPixelLighting();

  void begin(uint8_t pin, uint16_t numPixels);
  void update();

  bool addEffect(IEffect *effect);
  uint8_t getEffectIdx(IEffect *effect);

  inline uint8_t getNumEffects() const
  {
    return m_numEffects;
  }

  uint8_t getBrightness() const
  {
    return m_leds->getBrightness();
  }

  inline uint8_t getCurrentEffectIdx() const
  {
    return m_currentEffectIdx;
  }

  bool addController(IController *controller);

  void setOff();
  void setOn();
  void setBrightness(int16_t brightness);
  void switchToEffect(uint8_t effectIdx);

protected:
  Adafruit_NeoPixel *m_leds;

  IEffect *m_effects[MAX_NUM_EFFECTS];
  IController *m_controllers[MAX_NUM_CONTROLLERS];

  uint8_t m_numEffects;
  uint8_t m_numControllers;

  uint8_t m_currentEffectIdx;
  uint8_t m_brightnessBeforeOff;
};

#endif
