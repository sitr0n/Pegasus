#include "AMC.h"
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_STMPE610.h>
#include "user_interface.h"

#define STMPE_CS 16
#define TFT_CS   0
#define TFT_DC   15
#define SD_CS    2

// This is calibration data for the raw touch data to the screen coordinates
#define TS_MINX 3800
#define TS_MAXX 100
#define TS_MINY 100
#define TS_MAXY 3750

// Size of the color selection boxes and the paintbrush size
#define BOXSIZE 40
#define PENRADIUS 3

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
AMC aut = AMC(0.01, 0.05, 1);

void setup() {
  // put your setup code here, to run once:
  tft.begin();
  tft.fillScreen(ILI9341_BLACK);

  
}
int i = 0;
int sensor = 0;
int delay1 = 0;
int delay2 = 0;
uint32_t reg_k = 0;

void loop() {
  if (i++ < tft.width()){
    uint32_t reg = aut.tick(120, sensor);
    sensor = delay1;
    delay1 = delay2;
    delay2 = reg;
    for(int j = (int) reg_k; j < (int) sensor; j++){
      tft.drawPixel(i-1, j, ILI9341_CYAN);
    }
    tft.drawPixel(i, 120, ILI9341_RED);
    tft.drawPixel(i, sensor, ILI9341_CYAN);
    reg_k = sensor;
  }
}
