#ifndef _IRCONTROLLER_H_
#define _IRCONTROLLER_H_

#include <inttypes.h>

#include "../IController.h"

/* TODO */

class IRController : public IController
{
public:
  IRController();

  virtual void update() override;
};

#endif
