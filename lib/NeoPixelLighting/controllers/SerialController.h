#ifndef _SERIALCONTROLLER_H_
#define _SERIALCONTROLLER_H_

#include <inttypes.h>
#include <Stream.h>

#include "../IController.h"

class SerialController : public IController
{
public:
  static const uint16_t BUFFER_LEN = 64;

public:
  SerialController(Stream &stream);

  virtual bool testTransfer(uint8_t *nextEffectIdx) override;

protected:
  void bufferReset();

protected:
  Stream &m_stream;
  char m_buffer[BUFFER_LEN];
  uint16_t m_bufferPos;
};

#endif
