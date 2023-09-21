#ifndef CONFIG_H
#define CONFIG_H

#include <Adafruit_NeoPixel.h>

int PIN = 8;
int NUMLEDS = 60;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMLEDS, PIN, NEO_GRB + NEO_KHZ800);

#endif // CONFIG_H