#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "config.h"

char receivedChar = '0'; // Domyślny tryb

void setup()
{
  strip.begin();
  strip.show();
  strip.setBrightness(255);
  Serial.begin(9600);
}

// Funkcja animacja komenty
void commet()
{
  unsigned long startTime = millis();
  unsigned long elapsedTime = 0;
  unsigned long commetTime = 30000;

  while (elapsedTime < commetTime)
  {
    for (int i = NUMLEDS - 1; i >= 0; i--)
    {
      for (int j = 0; j < NUMLEDS; j++)
      {
        int brightness = map((j + i) % NUMLEDS, 0, NUMLEDS / 2, 0, 255);
        brightness = constrain(brightness, 0, 255);
        if ((j + i) % NUMLEDS >= NUMLEDS / 2)
        {
          strip.setPixelColor(j, strip.Color(0, 0, 0));
        }
        else
        {
          strip.setPixelColor(j, strip.Color(0, brightness, brightness));
        }
      }
      strip.show();
      delay(30);

      elapsedTime = millis() - startTime;
    }
  }
}

// Funkcja tęczy
void rainbow()
{
  unsigned long startTime = millis();
  unsigned long elapsedTime = 0;
  unsigned long rainbowTime = 30000;
  int rainbow = 0;

  while (elapsedTime < rainbowTime)
  {
    strip.rainbow(rainbow);
    strip.show();
    delay(15);

    elapsedTime = millis() - startTime;
    rainbow -= 256;
  }
}

// Przykład zmiany trybu na "2" - stały kolor fioletowy
void colors()
{
  for (uint16_t i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, strip.Color(255, 0, 0));
    strip.show();
    delay(20);
  }

  for (uint16_t i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, strip.Color(255, 100, 0));
    strip.show();
    delay(20);
  }

  for (uint16_t i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, strip.Color(255, 255, 0));
    strip.show();
    delay(20);
  }

  for (uint16_t i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, strip.Color(0, 255, 0));
    strip.show();
    delay(20);
  }

  for (uint16_t i = 0; i <= strip.numPixels(); i++)
  {
    strip.setPixelColor(i, strip.Color(0, 255, 255));
    strip.show();
    delay(20);
  }

  for (uint16_t i = 0; i <= strip.numPixels(); i++)
  {
    strip.setPixelColor(i, strip.Color(0, 0, 255));
    strip.show();
    delay(20);
  }

  for (uint16_t i = 0; i <= strip.numPixels(); i++)
  {
    strip.setPixelColor(i, strip.Color(255, 0, 255));
    strip.show();
    delay(20);
  }

  for (uint16_t i = 0; i <= strip.numPixels(); i++)
  {
    strip.setPixelColor(i, strip.Color(0, 0, 0));
    strip.show();
    delay(20);
  }
}

// Funkcja animacji do środka
void toCenter()
{
  for (uint16_t i = 0; i < strip.numPixels() / 2; i++)
  {
    strip.setPixelColor(i, strip.Color(255, 0, 0));
    strip.setPixelColor(strip.numPixels() - 1 - i, strip.Color(255, 0, 0));
    strip.show();
    delay(30);
  }

  for (uint16_t i = 0; i < strip.numPixels() / 2; i++)
  {
    strip.setPixelColor(i, strip.Color(255, 100, 0));
    strip.setPixelColor(strip.numPixels() - 1 - i, strip.Color(255, 100, 0));
    strip.show();
    delay(30);
  }

  for (uint16_t i = 0; i < strip.numPixels() / 2; i++)
  {
    strip.setPixelColor(i, strip.Color(255, 255, 0));
    strip.setPixelColor(strip.numPixels() - 1 - i, strip.Color(255, 255, 0));
    strip.show();
    delay(30);
  }

  for (uint16_t i = 0; i < strip.numPixels() / 2; i++)
  {
    strip.setPixelColor(i, strip.Color(0, 255, 0));
    strip.setPixelColor(strip.numPixels() - 1 - i, strip.Color(0, 255, 0));
    strip.show();
    delay(30);
  }

  for (uint16_t i = 0; i < strip.numPixels() / 2; i++)
  {
    strip.setPixelColor(i, strip.Color(0, 255, 255));
    strip.setPixelColor(strip.numPixels() - 1 - i, strip.Color(0, 255, 255));
    strip.show();
    delay(30);
  }

  for (uint16_t i = 0; i < strip.numPixels() / 2; i++)
  {
    strip.setPixelColor(i, strip.Color(0, 0, 255));
    strip.setPixelColor(strip.numPixels() - 1 - i, strip.Color(0, 0, 255));
    strip.show();
    delay(30);
  }

  for (uint16_t i = 0; i < strip.numPixels() / 2; i++)
  {
    strip.setPixelColor(i, strip.Color(255, 0, 255));
    strip.setPixelColor(strip.numPixels() - 1 - i, strip.Color(255, 0, 255));
    strip.show();
    delay(30);
  }

  for (uint16_t i = 0; i < strip.numPixels() / 2; i++)
  {
    strip.setPixelColor(i, strip.Color(0, 0, 0));
    strip.setPixelColor(strip.numPixels() - 1 - i, strip.Color(0, 0, 0));
    strip.show();
    delay(30);
  }
}

// Tryb białego światła
void white()
{
  for (uint16_t i = 100; i < 255; i++)
  {
    strip.fill(strip.Color(i, i, i - 50));
    strip.show();
    delay(50);
  }

  for (uint16_t i = 255; i >= 100; i--)
  {
    strip.fill(strip.Color(i, i, i - 50));
    strip.show();
    delay(50);
  }
}

// Tryb resetujcy - wyłącz wszystkie diody
void allOff()
{
  strip.fill(strip.Color(0, 0, 0));
  strip.show();
}

void loop()
{
  if (Serial.available() > 0)
  {
    receivedChar = Serial.read();
  }

  if (receivedChar == '1')
  {
    rainbow(); // Przykład zmiany trybu na "1"
  }
  else if (receivedChar == '2')
  {
    colors(); // Przykład zmiany trybu na "2"
  }
  else if (receivedChar == '3')
  {
    toCenter(); // Przykład zmiany trybu na "3"
  }
  else if (receivedChar == '4')
  {
    commet(); // Przykład zmiany trybu na "4"
  }
  else if (receivedChar == '5')
  {
    white(); // Przykład zmiany trybu na "5"
  }
  else if (receivedChar == '9')
  {
    allOff(); // Przykład zmiany trybu na "9"
  }
}