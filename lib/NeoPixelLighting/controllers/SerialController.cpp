#include "SerialController.h"

#include "../NeoPixelLighting.h"

SerialController::SerialController(Stream &stream)
    : m_stream(stream)
{
  bufferReset();
}

void SerialController::update()
{
  while (m_stream.available())
  {
    char c = m_stream.read();
    m_buffer[m_bufferPos++] = c;

    if (c == ';')
    {
      char command;
      int16_t data;
      sscanf(m_buffer, "%c=%i;", &command, &data);

      switch (command)
      {
      case 'B':
      case 'b':
        m_host->setBrightness(data);
        break;

      case 'E':
      case 'e':
        m_host->switchToEffect(data);
        break;

      default:
        m_stream.println("dafuq?");
      }

      bufferReset();
    }
  }
}

void SerialController::onSetBrightness(uint8_t brightness)
{
  m_stream.print("brightness=");
  m_stream.println(brightness);
}

void SerialController::onSetEffect(uint8_t effectIdx)
{
  m_stream.print("effect=");
  m_stream.println(effectIdx);
}

void SerialController::bufferReset()
{
  m_bufferPos = 0;
  memset(m_buffer, '\0', BUFFER_LEN);
}
