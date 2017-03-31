#include "IRController.h"

#ifndef NO_IR

#include "../NeoPixelLighting.h"

IRController::IRController(uint8_t rxPin, IRControllerRemote remote,
                           uint8_t brightnessDelta)
    : m_receiver(rxPin)
    , m_decoder()
    , m_remote(remote)
    , m_brightnessDelta(brightnessDelta)
{
  m_receiver.enableIRIn();
}

void IRController::update()
{
  if (m_receiver.getResults())
  {
    m_decoder.decode();

    if (m_decoder.protocolNum == m_remote.protocolNumber &&
        m_decoder.value != REPEAT_CODE)
    {
      uint8_t command;

      for (command = 0; command < IR_COMMAND_LENGTH; command++)
      {
        if (m_remote.commandValues[command] == m_decoder.value)
        {
          Serial.println(command);
          handleCommand(command);
          break;
        }
      }

    }

    m_receiver.enableIRIn();
  }
}

void IRController::handleCommand(IRControllerCommand command)
{
  switch(command)
  {
    case IR_COMMAND_OFF:
      m_host->setOff();
      break;

    case IR_COMMAND_ON:
      m_host->setOn();
      break;

    case IR_COMMAND_DIMMER:
      m_host->setBrightness(m_host->getBrightness() - m_brightnessDelta);
      break;

    case IR_COMMAND_BRIGHTER:
      m_host->setBrightness(m_host->getBrightness() + m_brightnessDelta);
      break;

    case IR_COMMAND_FLASH:
    case IR_COMMAND_STROBE:
    case IR_COMMAND_FADE:
    case IR_COMMAND_SMOOTH:
    case IR_COMMAND_RED:
    case IR_COMMAND_GREEN:
    case IR_COMMAND_BLUE:
    case IR_COMMAND_WHITE:
    case IR_COMMAND_COL_01:
    case IR_COMMAND_COL_02:
    case IR_COMMAND_COL_03:
    case IR_COMMAND_COL_04:
    case IR_COMMAND_COL_05:
    case IR_COMMAND_COL_06:
    case IR_COMMAND_COL_07:
    case IR_COMMAND_COL_08:
    case IR_COMMAND_COL_09:
    case IR_COMMAND_COL_10:
    case IR_COMMAND_COL_11:
    case IR_COMMAND_COL_12:
      m_host->switchToEffect(command - IR_COMMAND_FLASH);
      break;
  }
}

#endif
