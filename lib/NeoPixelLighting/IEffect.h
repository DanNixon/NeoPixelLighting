#pragma once

#include <Adafruit_NeoPixel.h>

class IEffect
{
  friend class NeoPixelLighting;

public:
  IEffect();
  virtual ~IEffect();

  virtual void onEntry()
  {
  }

  virtual void onOperate()
  {
    delay(10);
  }

  virtual void onExit()
  {
  }

protected:
  void setAllLEDs(uint32_t colour);

protected:
  Adafruit_NeoPixel *m_leds;
};
