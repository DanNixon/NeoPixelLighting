#include "SerialController.h"

#include "../NeoPixelLighting.h"

SerialController::SerialController(Stream &stream)
    : m_stream(stream)
{
  bufferReset();
}

bool SerialController::testTransfer(uint8_t *nextEffectIdx)
{
bool retVal = false;

  while (m_stream.available())
  {
    char c = m_stream.read();
    m_buffer[m_bufferPos++] = c;

    if (c == ';')
    {
      char command;
      int16_t data;
      sscanf(m_buffer, "%c=%i;", &command, &data);

      switch(command)
      {
        case 'B':
        case 'b':
          m_host->setBrightness(data);
          m_stream.print("brightness=");
          m_stream.println(data);
          break;

        case 'E':
        case 'e':
          *nextEffectIdx = data;
          retVal = true;
          m_stream.print("effect=");
          m_stream.println(data);
          break;

        default:
          m_stream.println("dafuq?");
      }

      bufferReset();
    }
  }

  return retVal;
}

void SerialController::bufferReset()
{
  m_bufferPos = 0;
  memset(m_buffer, '\0', BUFFER_LEN);
}
