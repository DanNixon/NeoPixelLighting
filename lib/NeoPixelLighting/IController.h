#ifndef _ICONTROLLER_H_
#define _ICONTROLLER_H_

class NeoPixelLighting;

class IController
{
  friend class NeoPixelLighting;

public:
  IController()
      : m_host(nullptr)
  {
  }

  virtual void update() = 0;

  virtual void onSetBrightness(uint8_t brightness)
  {
  }

  virtual void onSetEffect(uint8_t effectIdx)
  {
  }

protected:
  NeoPixelLighting *m_host;
};

#endif
