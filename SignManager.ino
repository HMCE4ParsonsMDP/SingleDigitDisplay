// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      120

// Segment starts and ends
#define A_START 0
#define A_END   14
#define B_START 103
#define B_END   116
#define C_START 18
#define C_END   28
#define D_START 73
#define D_END   84
#define E_START 60
#define E_END   69
#define F_START 29
#define F_END   39
#define G_START 43
#define G_END   57

#define DIM_WHITE pixels.Color(50, 50, 50)

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);



// Functions to turn segments on and off
void turnOffStrip() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, 0);
  }
  //pixels.show()
}

void lightOneSegment(int startPixel, int stopPixel, uint32_t color) {
  for (int i = startPixel; i <= stopPixel; i++) {
    pixels.setPixelColor(i, color);
  }
  //pixels.show();
}

bool contains(String parent, String child) {
  return parent.indexOf(child) >= 0;
}

void lightSegments(String segments, uint32_t color) {
  if (contains(segments, "A")) {
    lightOneSegment(A_START, A_END, color);
  }

  if (contains(segments, 'B')) {
    lightOneSegment(B_START, B_END, color);
  }

  if (contains(segments, 'C')) {
    lightOneSegment(C_START, C_END, color);
  }

  if (contains(segments, 'D')) {
    lightOneSegment(D_START, D_END, color);
  }

  if (contains(segments, 'E')) {
    lightOneSegment(E_START, E_END, color);
  }

  if (contains(segments, 'F')) {
    lightOneSegment(F_START, F_END, color);
  }

  if (contains(segments, 'G')) {
    lightOneSegment(G_START, G_END, color);
  }

  //pixels.show();
}

String numberMapping(int n) {
  switch (n) {
    case 0: return "ABCEFG";
    case 1: return "CF";
    case 2: return "ACDEG";
    case 3: return "ACDFG";
    case 4: return "BCDF";
    case 5: return "ABDFG";
    case 6: return "ABDEFG";
    case 7: return "ACF";
    case 8: return "ABCDEFG";
    case 9: return "ABCDF";
    default: return "ABDEG";
  }
}

void lightNumber(int n, uint32_t color) {
  lightSegments(numberMapping(n), color);
  pixels.show();
}


int delayval = 500; // delay for half a second

void setup() {

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  //for (int i = 0; i < 7; ++i) {
    lightNumber(1, pixels.Color(255,0,0));
    //delay(1000);
  //}
}
