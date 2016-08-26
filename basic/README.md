# Basic controller

Simple controller for a NeoPixel strip to be used for very basic lighting.

The controller mode is set by reading and incrementing an EEPROM value every
power cycle, allowing the mode to be set using the reset button alone thus other
than a decoupling capacitor no other components are needed (and even that can be
overlooked for serious simplicity).

Modes can either be static, in which case they have an initial colour defined in
`modes` and no hander in `loop()`, or dynamic, in which case they have both an
initial colour in `modes` and update code in `loop()`.

High power mode can be enabled by grounding pin 12, in this mode brightness is
set to 255 regardless of the value defined in `modes`.
