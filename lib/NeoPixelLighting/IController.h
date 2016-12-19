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

  virtual bool testTransfer(uint8_t *nextEffectIdx) = 0;

protected:
  NeoPixelLighting *m_host;
};

#endif
