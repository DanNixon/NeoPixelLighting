#pragma once

#include <inttypes.h>
#include <Stream.h>

#include "../IController.h"

class SerialController : public IController
{
public:
  static const uint16_t BUFFER_LEN = 64;

public:
  SerialController(Stream &stream);

  virtual void update() override;
  virtual void onSetBrightness(uint8_t brightness) override;
  virtual void onSetEffect(uint8_t effectIdx) override;

protected:
  void bufferReset();

protected:
  Stream &m_stream;
  char m_buffer[BUFFER_LEN];
  uint16_t m_bufferPos;
};
