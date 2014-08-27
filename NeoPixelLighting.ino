#include <EEPROM.h>
#include <Adafruit_NeoPixel.h>

#define SERIAL_BAUD 115200

#define NEOPIXEL_PIN 7
#define PIXEL_COUNT 144

#define HIGH_POWER_MODE_PIN 12

#define PIXEL_DELAY_TIME 5
#define MODE_ADDR 0

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

#define NUM_MODES 10
uint8_t modes[NUM_MODES][4] =
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
    
    {0,   191, 255, 100},
  };

enum
{
  R = 0,
  G,
  B,
  BRT
};

uint8_t mode;
uint8_t high_power_mode = 0;

void setup() {
#ifdef SERIAL_BAUD
  Serial.begin(SERIAL_BAUD);
#endif

  strip.begin();
  strip.show();
  
  pinMode(HIGH_POWER_MODE_PIN, INPUT_PULLUP);
  high_power_mode = !digitalRead(HIGH_POWER_MODE_PIN);
  
  mode = get_mode();
  
#ifdef SERIAL_BAUD
  Serial.print("High power mode: ");
  Serial.println(high_power_mode);
  Serial.print("Mode: ");
  Serial.println(mode);
#endif

  uint8_t *mode_data = modes[mode];
  
#ifdef SERIAL_BAUD
  Serial.print("R=");
  Serial.println(mode_data[R]);
  Serial.print("G=");
  Serial.println(mode_data[G]);
  Serial.print("B=");
  Serial.println(mode_data[B]);
  Serial.print("BRT=");
  Serial.println(mode_data[BRT]);
#endif

  set_strip(mode_data[R], mode_data[G], mode_data[B], mode_data[BRT]);
}

void loop() {
}

uint8_t get_mode()
{
  uint8_t mode = EEPROM.read(MODE_ADDR);
  mode++;
  if(mode >= NUM_MODES)
    mode = 0;
  EEPROM.write(MODE_ADDR, mode);
  return mode;
}

void set_strip(uint8_t r, uint8_t g, uint8_t b, uint8_t brt)
{
  if(high_power_mode)
    brt = 255;
    
  strip.setBrightness(brt);
  strip.show();
  
  for(uint16_t i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, strip.Color(r, g, b));
    strip.show();
    delay(PIXEL_DELAY_TIME);
  }
}
