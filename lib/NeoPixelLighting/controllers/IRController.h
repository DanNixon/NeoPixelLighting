#pragma once

#include <inttypes.h>
#include <IRLib2.h>

#include "../IController.h"

enum IRControllerCommand
{
  IR_COMMAND_ON,
  IR_COMMAND_OFF,

  IR_COMMAND_DIMMER,
  IR_COMMAND_BRIGHTER,

  IR_COMMAND_FLASH,
  IR_COMMAND_STROBE,
  IR_COMMAND_FADE,
  IR_COMMAND_SMOOTH,

  IR_COMMAND_RED,
  IR_COMMAND_GREEN,
  IR_COMMAND_BLUE,
  IR_COMMAND_WHITE,

  IR_COMMAND_COL_01,
  IR_COMMAND_COL_02,
  IR_COMMAND_COL_03,
  IR_COMMAND_COL_04,
  IR_COMMAND_COL_05,
  IR_COMMAND_COL_06,
  IR_COMMAND_COL_07,
  IR_COMMAND_COL_08,
  IR_COMMAND_COL_09,
  IR_COMMAND_COL_10,
  IR_COMMAND_COL_11,
  IR_COMMAND_COL_12,

  IR_COMMAND_LENGTH
};

struct IRControllerRemote
{
  uint8_t protocolNumber;
  uint32_t commandValues[IR_COMMAND_LENGTH];
};

class IRController : public IController
{
public:
  IRController(uint8_t rxPin, IRControllerRemote remote, uint8_t brightnessDelta = 16);

  virtual void update() override;

protected:
  void handleCommand(IRControllerCommand command);

private:
  IRrecvPCI m_receiver;
  IRdecode m_decoder;
  IRControllerRemote m_remote;
  uint8_t m_brightnessDelta;
};
