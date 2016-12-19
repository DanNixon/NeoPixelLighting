#ifndef _SERIALCONTROLLER_H_
#define _SERIALCONTROLLER_H_

#include <inttypes.h>

#include "../IController.h"

/* TODO */

class SerialController : public IController
{
public:
  SerialController();

  virtual bool testTransfer(uint8_t *nextEffectIdx) override;
};

#endif
