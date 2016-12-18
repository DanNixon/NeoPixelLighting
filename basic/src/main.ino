#include <EEPROM.h>
#include <Adafruit_NeoPixel.h>

/* #define SERIAL_BAUD 115200 */

#define NEOPIXEL_PIN 7
#define PIXEL_COUNT 35

#define PIXEL_DELAY_TIME 5
#define MODE_ADDR 0

uint8_t mode;
Adafruit_NeoPixel strip =
    Adafruit_NeoPixel(PIXEL_COUNT, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

enum DataField
{
  DF_RED = 0,
  DF_GREEN,
  DF_BLUE,
  DF_BRIGHTNESS
};

enum Mode
{
  MODE_OFF = 0,

  MODE_RED,
  MODE_GREEN,
  MODE_BLUE,

  MODE_YELLOW,
  MODE_CYAN,
  MODE_MAGENTA,

  MODE_WHITE,
  MODE_BRIGHT_WHITE,

  MODE_WHEEL,

  MODE_COUNT
};

// clang-format off
uint8_t modes[MODE_COUNT][4] =
  {
    {0,   0,   0,   0},

    {255, 0,   0,   100},
    {0,   255, 0,   100},
    {0,   0,   255, 100},

    {255, 255, 0,   100},
    {0,   255, 255, 100},
    {255, 0,   255, 100},

    {255, 255, 255, 100},
    {255, 255, 255, 200},

    {0,   0,   0,   100}
  };
// clang-format on

void setup()
{
#ifdef SERIAL_BAUD
  Serial.begin(SERIAL_BAUD);
#endif

  strip.begin();
  strip.show();

  // Get current mode from EEPROM
  mode = get_mode();

#ifdef SERIAL_BAUD
  Serial.print("Mode: ");
  Serial.println(mode);
#endif

  // Get data for initial mode state
  uint8_t *mode_data = modes[mode];

#ifdef SERIAL_BAUD
  Serial.print("R=");
  Serial.println(mode_data[DF_RED]);
  Serial.print("G=");
  Serial.println(mode_data[DF_GREEN]);
  Serial.print("B=");
  Serial.println(mode_data[DF_BLUE]);
  Serial.print("BRT=");
  Serial.println(mode_data[DF_BRIGHTNESS]);
#endif

  // Set initial state
  set_strip(mode_data[DF_RED], mode_data[DF_GREEN], mode_data[DF_BLUE],
            mode_data[DF_BRIGHTNESS]);
}

void loop()
{
  // Handle dynamic modes
  switch (mode)
  {
  case MODE_WHEEL:
    // This is the Adafruit rainbow demo from their library
    // See: https://github.com/adafruit/Adafruit_NeoPixel
    uint16_t i, j;
    for (j = 0; j < 256; j++)
    {
      for (i = 0; i < strip.numPixels(); i++)
        strip.setPixelColor(i, wheel((i + j) & 255));
      strip.show();
      delay(25);
    }
    break;
  default:
      // Do nothing for static modes
      ;
  }
}

/**
 * Gets the current mode from EEPROM and incrments value.
 */
uint8_t get_mode()
{
  uint8_t mode = EEPROM.read(MODE_ADDR);
  mode++;
  if (mode >= MODE_COUNT)
    mode = 0;
  EEPROM.write(MODE_ADDR, mode);
  return mode;
}

/**
 * Sets the brightness and colour of the entire strip.
 */
void set_strip(uint8_t r, uint8_t g, uint8_t b, uint8_t brt)
{
  strip.setBrightness(brt);
  strip.show();

  for (uint16_t i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, strip.Color(r, g, b));
    strip.show();
    delay(PIXEL_DELAY_TIME);
  }
}

uint32_t wheel(byte wheel_pos)
{
  if (wheel_pos < 85)
  {
    return strip.Color(wheel_pos * 3, 255 - wheel_pos * 3, 0);
  }
  else if (wheel_pos < 170)
  {
    wheel_pos -= 85;
    return strip.Color(255 - wheel_pos * 3, 0, wheel_pos * 3);
  }
  else
  {
    wheel_pos -= 170;
    return strip.Color(0, wheel_pos * 3, 255 - wheel_pos * 3);
  }
}
