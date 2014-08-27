NeoPixelLighting
================

A no frills NeoPixel lighting system

Simple controller for a NeoPixel strip to be used for very basic lighting.

The controller mode is set by reading and incrementing an EEPROM value every power cycle, allowing the mode to be set using the reset button alone thus other than a decoupling capacitor no other components are needed (and even that can be overlooked for serious simplicity).
