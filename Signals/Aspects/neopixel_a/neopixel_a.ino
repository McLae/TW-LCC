#include <Adafruit_NeoPixel.h>

///////////////////////////////////////////
char IdString[] = "neopixel test 1.0.0 3/16/2023";

#define PIN 2  // input pin Neopixel is attached to

#define NUMPIXELS 3  // number of neopixels in strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500;  // timing delay in milliseconds

int redColor = 0;
int greenColor = 0;
int blueColor = 0;

void setup() {
  Serial.begin(115200);
  Serial.println(IdString);
  // Initialize the NeoPixel library.
  pixels.begin();
  pixels.clear();
}

void loop() {
  setColor();
  pixels.clear();
  pixels.show();

  for (int i = 0; i < NUMPIXELS; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));
    Serial.print(redColor);
    Serial.print("-");
    Serial.print(greenColor);
    Serial.print("-");
    Serial.println(blueColor);

    // This sends the updated pixel color to the hardware.
    pixels.show();

    // Delay for a period of time (in milliseconds).
    delay(1000);
    pixels.setPixelColor(i, pixels.Color(120, 0, 0));
    pixels.show();
    delay(1000);
    pixels.setPixelColor(i, pixels.Color(0, 120, 0));
    pixels.show();
    delay(1000);
    pixels.setPixelColor(i, pixels.Color(120, 0, 120));
    pixels.show();
    delay(1000);
  }
  int x;
  int y;
  int z;
  uint32_t iColor;

  for (int x = 0; x < 14; x++) {
    for (int y = 0; y < 14; y++) {
      for (int z = 0; z < 14; z++) {
        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        iColor = pixels.Color(x, y, z);

        pixels.setPixelColor(0, x, y, z, 55);
        delay(delayval);
        pixels.show();
        pixels.setPixelColor(1, iColor);
        delay(delayval);
        // This sends the updated pixel color to the hardware.
        pixels.show();

        Serial.print(iColor);
        Serial.print(" RGB-");
        Serial.print(x);
        Serial.print("-");
        Serial.print(y);
        Serial.print("-");
        Serial.println(z);
        // Delay for a period of time (in milliseconds).
        delay(delayval);
      }
    }
  }
}

// setColor()
// picks random values to set for RGB
void setColor() {
  redColor = random(0, 2);
  greenColor = random(0, 2);
  blueColor = random(0, 2);
}