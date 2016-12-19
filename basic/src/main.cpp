#include <EEPROM.h>
#include <Adafruit_NeoPixel.h>

#include "IEffect.h"
#include "effects/StaticColour.h"
#include "effects/Wheel.h"
#include "effects/LowPowerSparkle.h"

#define SERIAL_BAUD 115200

#define NEOPIXEL_PIN 7
#define PIXEL_COUNT 35

#define MODE_ADDR 0

uint8_t g_currentEffectIdx;
Adafruit_NeoPixel strip =
    Adafruit_NeoPixel(PIXEL_COUNT, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

#define EFFECT_COUNT 10
IEffect *g_effects[EFFECT_COUNT] = {
  new IEffect(strip),
  new StaticColour(strip, 255, 0, 0),
  new StaticColour(strip, 0, 255, 0),
  new StaticColour(strip, 0, 0, 255),
  new StaticColour(strip, 255, 255, 0),
  new StaticColour(strip, 0, 255, 255),
  new StaticColour(strip, 255, 0, 255),
  new StaticColour(strip, 255, 255, 255),
  new Wheel(strip),
  new LowPowerSparkle(strip, 120)
};

uint8_t get_effect_idx();
void set_strip(uint8_t r, uint8_t g, uint8_t b, uint8_t brt);

void setup()
{
#ifdef SERIAL_BAUD
  Serial.begin(SERIAL_BAUD);
#endif

  strip.begin();
  strip.show();
  strip.setBrightness(200);
  strip.show();

  // Get current effect index from EEPROM
  g_currentEffectIdx = get_effect_idx();

#ifdef SERIAL_BAUD
  Serial.print("Effect: ");
  Serial.println(g_currentEffectIdx);
#endif

  // Set initial state
  g_effects[g_currentEffectIdx]->onEntry();
}

void loop()
{
  // Update dynamic state
  g_effects[g_currentEffectIdx]->onOperate();
}

/**
 * Gets the current effect index from EEPROM and incrments value.
 */
uint8_t get_effect_idx()
{
  uint8_t idx = EEPROM.read(MODE_ADDR);
  idx++;
  if (idx >= EFFECT_COUNT)
    idx = 0;
  EEPROM.write(MODE_ADDR, idx);
  return idx;
}
