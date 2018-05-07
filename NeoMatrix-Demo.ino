                      

// ESP8266 testing a generic NeoMatrix 8X8 panel by FixYourLAN
// Published 5/1/18 ver 2.0

/*This is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as
published by the Free Software Foundation, either version 3 of
the License, or (at your option) any later version.
This software is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License, see
http://www.gnu.org/licenses/, for more details.
*/

//#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

// MATRIX DECLARATION:
#define mw 8   // Parameter 1 = width of EACH NEOPIXEL MATRIX (not total display)
#define mh 8   // Parameter 2 = height of each matrix
#define PIN D6 // Parameter 3 = number of matrices arranged horizontally
// Parameter 4 = number of matrices arranged vertically
// Parameter 5 = pin number (most are valid)
// Parameter 6 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the FIRST MATRIX; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs WITHIN EACH MATRIX are
//     arranged in horizontal rows or in vertical columns, respectively;
//     pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns WITHIN
//     EACH MATRIX proceed in the same order, or alternate lines reverse
//     direction; pick one.
//   NEO_TILE_TOP, NEO_TILE_BOTTOM, NEO_TILE_LEFT, NEO_TILE_RIGHT:
//     Position of the FIRST MATRIX (tile) in the OVERALL DISPLAY; pick
//     two, e.g. NEO_TILE_TOP + NEO_TILE_LEFT for the top-left corner.
//   NEO_TILE_ROWS, NEO_TILE_COLUMNS: the matrices in the OVERALL DISPLAY
//     are arranged in horizontal rows or in vertical columns, respectively;
//     pick one or the other.
//   NEO_TILE_PROGRESSIVE, NEO_TILE_ZIGZAG: the ROWS/COLUMS OF MATRICES
//     (tiles) in the OVERALL DISPLAY proceed in the same order for every
//     line, or alternate lines reverse direction; pick one.  When using
//     zig-zag order, the orientation of the matrices in alternate rows
//     will be rotated 180 degrees (this is normal -- simplifies wiring).
//   See example below for these values in action.
// Parameter 7 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 pixels)
//   NEO_GRB     Pixels are wired for GRB bitstream (v2 pixels)
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA v1 pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip)

Adafruit_NeoMatrix *matrix = new Adafruit_NeoMatrix(mw, mh, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS    + NEO_MATRIX_ZIGZAG,
  NEO_RGB            + NEO_KHZ800);

#include "Matrix-Demo-Arrays.h"
#include "MatrixColors.h"
#include "StripColors.h"
#include "Bitmaps.h"

// the setup routine runs once when you press reset:
void setup() {
    Serial.begin(115200);
    matrix->begin();
    matrix->setBrightness(BRIGHTNESS);
    matrix->setTextWrap(false);
    // Test full bright of all LEDs. If brightness is too high
    // for your current limit (i.e. USB), decrease it.
//    matrix->fillScreen(LED_WHITE_MEDIUM);
//    matrix->show();
//    delay(100);
    matrix->clear();
}

// the loop routine runs over and over again forever;
void loop() {
 matrix->clear();
 scrollMsg("Jim Bazar Made This",-116,STRIP_BLUE_HIGH,50,220);
 display_scrollText(50);
 load_panel(STRIP_RED_HIGH, 50);
 unload_panel(STRIP_GREEN_HIGH, 50); 
 load_panel(STRIP_BLUE_HIGH, 25);
 unload_panel(STRIP_BLACK, 10);                    
      
 color_all_fill(STRIP_RED_HIGH, 500);           
 color_all_fill(STRIP_GREEN_HIGH, 500);           
 color_all_fill(STRIP_BLUE_HIGH, 500);           
 color_all_fill(STRIP_ORANGE_HIGH, 500);    
 color_all_fill(STRIP_CYAN_HIGH, 500);    
 color_all_fill(STRIP_WHITE_HIGH, 500);    
 matrix->clear();
         
 // Fills the NeoMatrix 8X8 panel in a spiral then revers's it 
 spiral_color_wipe(STRIP_RED_HIGH, 50); 
 reverse_spiral_color_wipe(STRIP_GREEN_HIGH, 50); 
 spiral_color_wipe(STRIP_BLUE_HIGH, 50); 
 reverse_spiral_color_wipe(STRIP_ORANGE_HIGH, 25); 
 one_pixel_spiral_color_wipe(STRIP_PURPLE_HIGH, 15); 
 matrix->clear();        

 // Fills the NeoMatrix 8X8 panel using one 4X4 minimatrix at a time in the 8X8 panel
 four_matrixes_color_wipe(LED_RED_HIGH, 50);
 reverse_four_matrixes_color_wipe(LED_GREEN_HIGH, 50); 
 one_pixel_four_matrixes_color_wipe(LED_ORANGE_HIGH, 50); 
 matrix->clear(); 
             
 // Fills the NeoMatrix 8X8 panel using all of the 4X4 minimatrix 
 // at the same time in the 8X8 panel
 four_matrixes_same_color_wipe(STRIP_RED_HIGH, 50); 
 reverse_four_matrixes_same_color_wipe(STRIP_GREEN_HIGH, 50);
 one_pixel_four_matrixes_same_color_wipe(STRIP_BLUE_HIGH, 50); 
 four_matrixes_same_color_wipe(STRIP_ORANGE_HIGH, 50); 
 reverse_one_pixel_four_matrixes_same_color_wipe(STRIP_GREEN_HIGH, 50);
 matrix->clear();

 split_spiral_color_wipe(STRIP_RED_HIGH, 50);
 reverse_split_spiral_color_wipe(STRIP_GREEN_HIGH, 50);
 one_pixel_split_spiral_color_wipe(STRIP_BLUE_HIGH, 50);
 reverse_split_spiral_color_wipe(STRIP_GREEN_HIGH, 25);
 one_pixel_split_spiral_color_wipe(STRIP_RED_HIGH, 25);
 reverse_one_pixel_split_spiral_color_wipe(STRIP_BLUE_HIGH, 10);
 one_pixel_split_spiral_color_wipe(STRIP_GREEN_HIGH, 5);
 reverse_one_pixel_split_spiral_color_wipe(STRIP_RED_HIGH, 5);
 matrix->clear();

//===============================================================

Adafruit_NeoMatrix *matrix = new Adafruit_NeoMatrix(mw, mh, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS    + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);

    
    
    // clear the screen after X bitmaps have been displayed and we
    // loop back to the top left corner
    // 8x8 => 1, 16x8 => 2, 17x9 => 6
    static uint8_t pixmap_count = ((mw+7)/8) * ((mh+7)/8);
    Serial.print("Screen pixmap capacity: ");
    Serial.println(pixmap_count);
    
//    display_scrollText();
    display_all_one_color(LED_WHITE_HIGH,200);
    display_all_one_color(LED_WHITE_MEDIUM,200);
    display_all_one_color(LED_WHITE_LOW,200);
    display_all_one_color(LED_RED_HIGH,200);
    display_all_one_color(LED_RED_MEDIUM,200);
    display_all_one_color(LED_RED_LOW,200);
    display_all_one_color(LED_BLUE_HIGH,200);
    display_all_one_color(LED_BLUE_MEDIUM,200);
    display_all_one_color(LED_BLUE_LOW,200);
    display_all_one_color(LED_GREEN_HIGH,200);
    display_all_one_color(LED_GREEN_MEDIUM,200);
    display_all_one_color(LED_GREEN_LOW,200);
    display_all_one_color(LED_ORANGE_HIGH,200);
    display_all_one_color(LED_ORANGE_MEDIUM,200);
    display_all_one_color(LED_ORANGE_LOW,200);
    display_all_one_color(LED_CYAN_HIGH,200);
    display_all_one_color(LED_CYAN_MEDIUM,200);
    display_all_one_color(LED_CYAN_LOW,200);

    // multicolor bitmap sent as many times as we can display an 8x8 pixmap
    for (uint8_t i=0; i<=pixmap_count; i++)
          display_rgbBitmap(0,1000);
 
//    display_resolution(100);

    // Cycle through red, green, blue, display 2 checkered patterns
    // useful to debug some screen types and alignment.
    uint16_t bmpcolor[] = { LED_RED_HIGH, LED_BLUE_HIGH, LED_GREEN_HIGH };
    for (uint8_t i=0; i<3; i++){
      display_bitmap(0, bmpcolor[i],200);
      display_bitmap(1, bmpcolor[i],200);
      display_bitmap(0, bmpcolor[i],200);
      display_bitmap(1, bmpcolor[i],200);
      display_bitmap(0, bmpcolor[i],200);
      display_bitmap(1, bmpcolor[i],200);
    }

  
    for (uint8_t i=2; i<=4; i++)  // Display 3 smiley faces
       display_bitmap(i, bmpcolor[i-2],(mw>8?500:1000));
    display_lines(300); delay(2000);
    display_boxes(300); delay(2000);
    display_circles(300); delay(2000);
    matrix->clear();
    for (uint8_t i=0; i<=(sizeof(RGB_bmp)/sizeof(RGB_bmp[0])-1); i++)
       display_rgbBitmap(i,(mw>8?500:1000));
    display_four_white(600); delay(3000);
//    display_panOrBounceBitmap(24);  // pan a big pixmap
//    display_panOrBounceBitmap(8);   // bounce around a small one

//===============================================================
} // End of main Loop

// Functions for loop -----------------------------------------------------------------

// Fills down NeoMatrix 8X8 panel by the numbers in order 
// one neopixel after the other in pixel order
void load_panel(uint16_t c, uint16_t wait){    
   for(uint16_t i=0; i<matrix->numPixels(); i++) {
      matrix->setPixelColor(i, c);      
      matrix->show();
      delay(wait);
      }
}

// Fills up NeoMatrix 8X8 panel by the numbers in order 
// one neopixel after the other in pixel order
void unload_panel(int c, uint16_t wait){    
  for(uint16_t i=matrix->numPixels(); i>0; i--) {
      matrix->setPixelColor(i, c);      
      matrix->show();
      delay(wait);
     }
}

// Fills the NeoMatrix 8X8 panel with in a spiral
// one neopixel after the other
void spiral_color_wipe(int c, uint16_t wait) {    
  for(uint16_t j=0; j<4; j++) {
   uint16_t x=boxtotalarray[j];
    for(uint16_t k=0; k<x; k++) {
      matrix->setPixelColor(bigboxarray[j][k], c);     
      matrix->show();
      delay(wait);
     }
   }
}

// Fills the NeoMatrix 8X8 panel with in a reverse spiral 
//  one neopixel moving in reverse
void reverse_spiral_color_wipe(int c, int wait) {    
  for(int j=3; j>=0; j--) {
    int x=boxtotalarray[j];
    for(int k=x-1; k>=0; k--) {
      matrix->setPixelColor(bigboxarray[j][k], c); 
      matrix->show();
      delay(wait);
     }
  }
}

// Fills the each of 4 seperate 4X4 matrixes in the 
// NeoMatrix 8X8 panel with in a spiral 
// one neopixel after the other
void four_matrixes_color_wipe(int c, uint16_t wait) {    
   for(uint16_t j=0; j<4; j++) {
    for(uint16_t k=0; k<16; k++) {
      matrix->setPixelColor(bigfourarray[j][k], c);     
      matrix->show();
      delay(wait);
      }
  }
}  
// Reverse Fills the each of 4 seperate 4X4 matrixes in the 
// 8x8 NeoMatrix panel with in a reverse spiral 
// one neopixel after the other
void reverse_four_matrixes_color_wipe(int c, uint16_t wait) {    
   for(int j=3; j>=0; j--) {
    for(int k=15; k>=0; k--) {
      matrix->setPixelColor(bigfourarray[j][k], c);     
      matrix->show();
      delay(wait);
      }
  }
} 
// Draws one pixel in each of the 4 seperate 4X4 matrixes in a 
// 8x8 NeoMatrix panel with a moving pixrl in a spiral.
void one_pixel_four_matrixes_color_wipe(int c, uint16_t wait) {    
   for(uint16_t j=0; j<4; j++) {
    for(uint16_t k=0; k<16; k++) {
      matrix->setPixelColor(bigfourarray[j][k], c);     
      matrix->show();
      delay(wait);
      matrix->setPixelColor(bigfourarray[j][k], 0);     
      matrix->show();
      }
  }
}  
// Reverse PIXEL DRAW in each of 4 seperate 4X4 matrixes 
// in the NeoMatrix 8X8 panel with in a spiral
// only one neopixel moving in reverse
void reverse_one_pixel_four_matrixes_color_wipe(int c, uint16_t wait) {    
   for(int j=3; j>=0; j--) {
    for(int k=15; k>=0; k--) {
      matrix->setPixelColor(bigfourarray[j][k], c);     
      matrix->show();
      delay(wait);
      matrix->setPixelColor(bigfourarray[j][k], 0);     
      matrix->show();
      }
  }
}  

// PIXEL DRAW IN the all of the 4 seperate 4X4 matrixes in the 
// NeoMatrix 8X8 panel in a spiral -  one neopixel at a time 
// in each cube
void one_pixel_four_matrixes_same_color_wipe(int c, uint16_t wait) { 
  for(uint16_t k=0; k<16; k++) {
      matrix->setPixelColor(bigfourarray[0][k], c);    
      matrix->setPixelColor(bigfourarray[1][k], c); 
      matrix->setPixelColor(bigfourarray[2][k], c); 
      matrix->setPixelColor(bigfourarray[3][k], c);  
      matrix->show();
      delay(wait);
      matrix->setPixelColor(bigfourarray[0][k], 0);    
      matrix->setPixelColor(bigfourarray[1][k], 0); 
      matrix->setPixelColor(bigfourarray[2][k], 0); 
      matrix->setPixelColor(bigfourarray[3][k], 0);  
      matrix->show();
    }
}  
// Reverse Fills the 4 seperate 4X4 matrixes in the 
// NeoMatrix 8X8 panel in a spiral 
// one neopixel at a time in each of the 4 cubes
void reverse_one_pixel_four_matrixes_same_color_wipe(int c, uint16_t wait) { 
  for(int k=15; k>=0; k--) {
      matrix->setPixelColor(bigfourarray[0][k], c);    
      matrix->setPixelColor(bigfourarray[1][k], c); 
      matrix->setPixelColor(bigfourarray[2][k], c); 
      matrix->setPixelColor(bigfourarray[3][k], c);  
      matrix->show();
      delay(wait);
      matrix->setPixelColor(bigfourarray[0][k], 0);    
      matrix->setPixelColor(bigfourarray[1][k], 0); 
      matrix->setPixelColor(bigfourarray[2][k], 0); 
      matrix->setPixelColor(bigfourarray[3][k], 0);  
      matrix->show();
    }
}  

// Fills the all of the 4 seperate 4X4 matrixes in the 
// NeoMatrix 8X8 panel in a spiral 
// one neopixel after another in each cube
void four_matrixes_same_color_wipe(int c, uint16_t wait) { 
  for(uint16_t k=0; k<16; k++) {
      matrix->setPixelColor(bigfourarray[0][k], c);    
      matrix->setPixelColor(bigfourarray[1][k], c); 
      matrix->setPixelColor(bigfourarray[2][k], c); 
      matrix->setPixelColor(bigfourarray[3][k], c);  
      matrix->show();
      delay(wait);
    }
} 

// Reverse Fills the all of the 4 seperate 4X4 matrixes in the 
// NeoMatrix 8X8 panel in a REVERSE spiral 
// one neopixel after another in each cube
void reverse_four_matrixes_same_color_wipe(int c, uint16_t wait) { 
  for(int k=15; k>=16; k--) {
      matrix->setPixelColor(bigfourarray[3][k], c);    
      matrix->setPixelColor(bigfourarray[2][k], c); 
      matrix->setPixelColor(bigfourarray[1][k], c); 
      matrix->setPixelColor(bigfourarray[0][k], c);  
      matrix->show();
      delay(wait);
    }
} 
 
// Fills 4x8 panel half top and half bottom of 8x8 panel
// at same time together
void split_spiral_color_wipe(int c, uint16_t wait) {    
  for(uint16_t j=0; j<6; j+=2) {
    uint16_t x=splitboxtotalarray[j];
    for(uint16_t k=0; k<x; k++) {
      matrix->setPixelColor(splitbigboxarray[j][k], c);  
      matrix->setPixelColor(splitbigboxarray[j+1][k], c);    
      matrix->show();
      delay(wait);
      }
  }
}

// Reverse Fills the 4x8 NeoMatrix 8X8 panel top half
// and bottom half together in reverse
void reverse_split_spiral_color_wipe(int c, uint16_t wait) {    
  for(int j=5; j>=0; j-=2) {
    int x=splitboxtotalarray[j];
    for(int k=x-1; k>=0; k--) {
      matrix->setPixelColor(splitbigboxarray[j][k], c);  
      matrix->setPixelColor(splitbigboxarray[j-1][k], c);    
      matrix->show();
      delay(wait);
      }
  }
}

// move pixel in a 4x8 top/bottom half of NeoMatrix 8X8 panel  
// at a time together
void one_pixel_split_spiral_color_wipe(int c, uint16_t wait) {    
  for(int j=0; j<6; j+=2) {
    int x=splitboxtotalarray[j];
    for(int k=0; k<x; k++) {
      matrix->setPixelColor(splitbigboxarray[j][k], c);  
      matrix->setPixelColor(splitbigboxarray[j+1][k], c);    
      matrix->show();
      delay(wait);
      matrix->setPixelColor(splitbigboxarray[j][k], 0);  
      matrix->setPixelColor(splitbigboxarray[j+1][k], 0);    
      matrix->show();
      }
  }
}

// Reverse a pixel in a 4x8 top/bottom in a NeoMatrix 8X8 panel 
// half at a time together in reverse
void reverse_one_pixel_split_spiral_color_wipe(int c, uint16_t wait) {    
  for(int j=5; j>=0; j-=2) {
    int x=splitboxtotalarray[j];
    for(int k=x-1; k>=0; k--) {
      matrix->setPixelColor(splitbigboxarray[j][k], c);  
      matrix->setPixelColor(splitbigboxarray[j-1][k], c);   
      matrix->show();
      delay(wait);
      matrix->setPixelColor(splitbigboxarray[j][k], 0);  
      matrix->setPixelColor(splitbigboxarray[j-1][k], 0);    
      matrix->show();
      }
  }
}

// Fills the NeoMatrix 8X8 panel in a spiral 
// one neopixel after the other with only 
// one neoPixel lit at a time
void one_pixel_spiral_color_wipe(int c, uint16_t wait) {    
  for(uint16_t j=0; j<4; j++) {
   uint16_t x=boxtotalarray[j];
    for(uint16_t k=0; k<x; k++) {
      matrix->setPixelColor(bigboxarray[j][k], c);      
      matrix->show();
      delay(wait);
      matrix->setPixelColor(bigboxarray[j][k], 0);      
      matrix->show();
      }
  }
}

// Reverse Fills the NeoMatrix 8X8 panel in a spiral
// one neopixel after the other with only one neoPixel lit at a time
void reverse_one_pixel_spiral_color_wipe(int c, uint16_t wait) {    
    for(uint16_t j=3; j>=0; j--) {
    uint16_t x=boxtotalarray[j];
    for(uint16_t k=x-1; k>=0; k--) {
      matrix->setPixelColor(bigboxarray[j][k], c);      
      matrix->show();
      delay(wait);
      matrix->setPixelColor(bigboxarray[j][k], 0);      
      matrix->show();
     }
  }
}

// Fills the NeoMatrix 8X8 panel in a squares 
// one square after the other
void box_color_wipe(int c, uint16_t wait) {    
  for(uint16_t j=0; j<4; j++) {
    uint16_t x=boxtotalarray[j];
    for(uint16_t k=0; k<x; k++) {
      matrix->setPixelColor(bigboxarray[j][k], c);            
     } 
     matrix->show();
     delay(wait); 
   }
}

// Fills the NeoMatrix 8X8 panel - one square at a time
void full_all_box_color_wipe(int c, uint16_t wait, uint8_t* boxarray, int x) { // Note: boxarray is the name of the array being used.  x is the number of members in the array being used.
  
 for(uint16_t i=0; i<x; i++) {
    matrix->setPixelColor(boxarray[i], c);     
    }   
    matrix->show();
    delay(wait);   
} 

// Fills the NeoMatrix 8X8 panel with all of the NeoPixes at one time 
void color_all_fill(int c, uint16_t wait) {  
  for(uint16_t i=0; i<matrix->numPixels(); i++) {
    matrix->setPixelColor(i, c);      
    }       
    matrix->show();
    delay(wait);   
}      
/*  //test code
// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) { // cycle all colors
    for(i=0; i< matrix->numPixels(); i++) {
      matrix->setColor(i, Wheel(((i * 256 / matrix->.numPixels()) + j) & 255));
    }
    matrix->show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return matrix->Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return matrix->Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return matrix->strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
} 
*/ //end of test code
//================================================================
// Convert a BGR 4/4/4 bitmap to RGB 5/6/5 used by Adafruit_GFX
void fixdrawRGBBitmap(int16_t x, int16_t y, const uint16_t *bitmap, int16_t w, int16_t h) {
    uint16_t RGB_bmp_fixed[w * h];
    for (uint16_t pixel=0; pixel<w*h; pixel++) {
      uint8_t r,g,b;
      uint16_t color = pgm_read_word(bitmap + pixel);

      //Serial.print(color, HEX);
      b = (color & 0xF00) >> 8;
      g = (color & 0x0F0) >> 4;
      r = color & 0x00F;
      //Serial.print(" ");
      //Serial.print(b);
      //Serial.print("/");
      //Serial.print(g);
      //Serial.print("/");
      //Serial.print(r);
      //Serial.print(" -> ");
      // expand from 4/4/4 bits per color to 5/6/5
      b = map(b, 0, 15, 0, 31);
      g = map(g, 0, 15, 0, 63);
      r = map(r, 0, 15, 0, 31);
      //Serial.print(r);
      //Serial.print("/");
      //Serial.print(g);
      //Serial.print("/");
      //Serial.print(b);
      RGB_bmp_fixed[pixel] = (r << 11) + (g << 5) + b;
      //Serial.print(" -> ");
      //Serial.println(RGB_bmp_fixed[pixel], HEX);
    }
    matrix->drawRGBBitmap(x, y, RGB_bmp_fixed, w, h);
}
void display_all_one_color(int color, int wait)
{
    matrix->clear();
    matrix->fillScreen(color);
    matrix->show();
    delay(wait);
}

// Fill the screen with multiple levels of white to gauge the quality
void display_four_white(int wait) {
    matrix->clear();
    matrix->fillRect(0,0, mw,mh, LED_WHITE_HIGH);
    matrix->show();
    delay(wait);
    matrix->drawRect(1,1, mw-2,mh-2, LED_WHITE_MEDIUM);
    matrix->show();
    delay(wait);
    matrix->drawRect(2,2, mw-4,mh-4, LED_WHITE_LOW);
    matrix->show();
    delay(wait);
//    matrix->drawRect(3,3, mw-6,mh-6, LED_WHITE_VERYLOW);
    matrix->show();
}

void display_bitmap(uint8_t bmp_num, uint16_t color,int wait) { 
    static uint16_t bmx,bmy;

    // Clear the space under the bitmap that will be drawn as
    // drawing a single color pixmap does not write over pixels
    // that are nul, and leaves the data that was underneath
    matrix->fillRect(bmx,bmy, bmx+8,bmy+8, LED_BLACK);
    matrix->drawBitmap(bmx, bmy, mono_bmp[bmp_num], 8, 8, color);
    bmx += 8;
    if (bmx >= mw) bmx = 0;
    if (!bmx) bmy += 8;
    if (bmy >= mh) bmy = 0;
    matrix->show();
    delay(wait);
}

void display_rgbBitmap(uint8_t bmp_num,int wait) { 
    static uint16_t bmx,bmy;

    fixdrawRGBBitmap(bmx, bmy, RGB_bmp[bmp_num], 8, 8);
    bmx += 8;
    if (bmx >= mw) bmx = 0;
    if (!bmx) bmy += 8;
    if (bmy >= mh) bmy = 0;
    matrix->show();
    delay(wait);
}

void display_lines(int wait) {
    matrix->clear();

    // 4 levels of crossing red lines.
    matrix->drawLine(0,mh/2-2, mw-1,2, LED_RED_VERYLOW);
    matrix->show();
    delay(wait);
    matrix->drawLine(0,mh/2-1, mw-1,3, LED_RED_LOW);
    matrix->show();
    delay(wait);
    matrix->drawLine(0,mh/2,   mw-1,mh/2, LED_RED_MEDIUM);
    matrix->show();
    delay(wait);
    matrix->drawLine(0,mh/2+1, mw-1,mh/2+1, LED_RED_HIGH);

    // 4 levels of crossing green lines.
//    matrix->drawLine(mw/2-2, 0, mw/2-2, mh-1, LED_GREEN_VERYLOW);
    matrix->show();
    delay(wait);
    matrix->drawLine(mw/2-1, 0, mw/2-1, mh-1, LED_GREEN_LOW);
    matrix->show();
    delay(wait);
    matrix->drawLine(mw/2+0, 0, mw/2+0, mh-1, LED_GREEN_MEDIUM);
    matrix->show();
    delay(wait);
    matrix->drawLine(mw/2+1, 0, mw/2+1, mh-1, LED_GREEN_HIGH);
    matrix->show();
    delay(wait);
    // Diagonal blue line.
    matrix->drawLine(0,0, mw-1,mh-1, LED_BLUE_HIGH);
    matrix->show();
    delay(wait);
    matrix->drawLine(0,mh-1, mw-1,0, LED_ORANGE_HIGH);
    matrix->show();
    delay(wait);}

void display_boxes(int wait) {
    matrix->clear();
    matrix->drawRect(0,0, mw,mh, LED_BLUE_HIGH);
    matrix->show();
    delay(wait);
    matrix->drawRect(1,1, mw-2,mh-2, LED_GREEN_MEDIUM);
    matrix->show();
    delay(wait);
    matrix->drawRect(2,2, mw-4,mh-4, LED_RED_HIGH);
    matrix->show();
    delay(wait);

    matrix->fillRect(3,3, mw-6,mh-6, LED_ORANGE_MEDIUM);
    matrix->show();
    delay(wait);
    matrix->fillRect(3,3, mw-6,mh-6, LED_BLUE_MEDIUM);
    matrix->show();
    delay(wait);
    matrix->drawRect(2,2, mw-4,mh-4, LED_ORANGE_HIGH);
    matrix->show();
    delay(wait);
    matrix->drawRect(1,1, mw-2,mh-2, LED_BLUE_MEDIUM);
    matrix->show();
    delay(wait); 
    matrix->drawRect(0,0, mw,mh, LED_RED_HIGH);
    matrix->show();
    delay(wait);   
}

void display_circles(int wait) {
    matrix->clear();
    matrix->drawCircle(mw/2,mh/2, 2, LED_RED_MEDIUM);
    matrix->show();
    delay(wait);
    matrix->drawCircle(mw/2-1-min(mw,mh)/8, mh/2-1-min(mw,mh)/8, min(mw,mh)/4, LED_BLUE_HIGH);
    matrix->show();
    delay(wait);
    matrix->drawCircle(mw/2+1+min(mw,mh)/8, mh/2+1+min(mw,mh)/8, min(mw,mh)/4-1, LED_ORANGE_MEDIUM);
    matrix->show();
    delay(wait);
    matrix->drawCircle(1,mh-2, 1, LED_GREEN_LOW);
    matrix->show();
    delay(wait);
    matrix->drawCircle(mw-2,1, 1, LED_GREEN_HIGH);
    if (min(mw,mh)>12) matrix->drawCircle(mw/2-1, mh/2-1, min(mh/2-1,mw/2-1), LED_CYAN_HIGH);
    matrix->show();
}

void display_resolution(int wait) {
    // not wide enough;
    if (mw<16) return;
    matrix->clear();
    // Font is 5x7, if display is too small
    // 8 can only display 1 char
    // 16 can almost display 3 chars
    // 24 can display 4 chars
    // 32 can display 5 chars
    matrix->setCursor(0, 0);
    matrix->setTextColor(matrix->Color(255,0,0));
    if (mw>10) matrix->print(mw/10);
    matrix->setTextColor(matrix->Color(255,128,0)); 
    matrix->print(mw % 10);
    matrix->setTextColor(matrix->Color(0,255,0));
    matrix->print('x');
    // not wide enough to print 5 chars, go to next line
    if (mw<25) {
     if (mh==13) matrix->setCursor(6, 7);
     else if (mh>=13) { 
      matrix->setCursor(mw-11, 8);
       } else {
         matrix->show();
         delay(wait);
         matrix->clear();
         matrix->setCursor(mw-11, 0);
       }   
    }
    matrix->setTextColor(matrix->Color(0,255,128)); 
    matrix->print(mh/10);
    matrix->setTextColor(matrix->Color(0,128,255));  
    matrix->print(mh % 10);
    // enough room for a 2nd line
    if (mw>25 && mh >14 || mh>16) {
      matrix->setCursor(0, mh-7);
      matrix->setTextColor(matrix->Color(0,255,255)); 
      if (mw>16) matrix->print('*');
      matrix->setTextColor(matrix->Color(255,0,0)); 
      matrix->print('R');
      matrix->setTextColor(matrix->Color(0,255,0));
      matrix->print('G');
      matrix->setTextColor(matrix->Color(0,0,255)); 
      matrix->print("B");
      matrix->setTextColor(matrix->Color(255,255,0)); 
      matrix->print("*");
    }
    matrix->show();
}

void display_scrollText(int displayspeed) {
    matrix->clear();
    matrix->setTextWrap(false);  // we don't wrap text so it scrolls nicely
    matrix->setTextSize(1);
    matrix->setRotation(0);
    for (int8_t x=7; x>=-85; x--) {
      matrix->clear();
      matrix->setCursor(x,0);
      matrix->setTextColor(LED_ORANGE_MEDIUM);  matrix->print("N");
      matrix->setTextColor(LED_RED_MEDIUM);     matrix->print("e");
      matrix->setTextColor(LED_BLUE_MEDIUM);    matrix->print("o"); 
      matrix->setTextColor(LED_GREEN_MEDIUM);   matrix->print("M"); 
      matrix->setTextColor(LED_CYAN_MEDIUM);    matrix->print("a");
      matrix->setTextColor(LED_RED_MEDIUM);     matrix->print("t");
      matrix->setTextColor(LED_GREEN_MEDIUM);   matrix->print("r");
      matrix->setTextColor(LED_BLUE_MEDIUM);    matrix->print("i");  
      matrix->setTextColor(LED_ORANGE_MEDIUM);  matrix->print("x");  
      matrix->setTextColor(LED_PURPLE_MEDIUM);  matrix->print(" D");
      matrix->setTextColor(LED_RED_MEDIUM);     matrix->print("e");  
      matrix->setTextColor(LED_GREEN_MEDIUM);   matrix->print("m");  
      matrix->setTextColor(LED_BLUE_MEDIUM);    matrix->print("o");              
  
  if (mh>11) {
      matrix->setCursor(-20-x,mh-7);
      matrix->setTextColor(LED_ORANGE_HIGH);
      matrix->print("2pannel");
  }
  matrix->show();
       delay(displayspeed);
    }
    delay(1000);
//    matrix->setRotation(2);
//    matrix->setTextColor(LED_BLUE_HIGH);
//    for (int8_t x=7; x>=-70; x--) {
//      matrix->clear();
//      matrix->setCursor(x,mw/2-4);
//      matrix->print("Flipped OVER");
//      matrix->show();
//      delay(displayspeed);
//    }
      matrix->setRotation(0);
      matrix->setCursor(0,0);
      matrix->show();
}

void scrollMsg(char* msg,int msglength,int color,int displayspeed,int wait) {
    matrix->clear();
    matrix->setTextWrap(false);  // we don't wrap text so it scrolls nicely
    matrix->setTextSize(1);
    matrix->setRotation(0);
    for (int8_t x=8; x>msglength; x--) {
      matrix->clear();
      matrix->setCursor(x,0);
      matrix->setTextColor(color);
      matrix->print(msg);
      matrix->show();
      delay(displayspeed);
    }
    matrix->setCursor(0,0);
    delay(wait);
}

// Scroll within big bitmap so that all if it becomes visible or bounce a small one.
// If the bitmap is bigger in one dimension and smaller in the other one, it will
// be both panned and bounced in the appropriate dimensions.
void display_panOrBounceBitmap (uint8_t bitmapSize) {
    // keep integer math, deal with values 16 times too big
    // start by showing upper left of big bitmap or centering if the display is big
    int16_t xf = max(0, (mw-bitmapSize)/2) << 4;
    int16_t yf = max(0, (mh-bitmapSize)/2) << 4;
    // scroll speed in 1/16th
    int16_t xfc = 6;
    int16_t yfc = 3;
    // scroll down and right by moving upper left corner off screen 
    // more up and left (which means negative numbers)
    int16_t xfdir = -1;
    int16_t yfdir = -1;
    for (uint16_t i=1; i<1000; i++) {
      bool updDir = false;
      // Get actual x/y by dividing by 16.
      int16_t x = xf >> 4;
      int16_t y = yf >> 4;
      matrix->clear();
      // bounce 8x8 tri color smiley face around the screen
      if  (bitmapSize == 8) fixdrawRGBBitmap(x, y, RGB_bmp[10], 8, 8);
       // pan 24x24 pixmap
      if (bitmapSize == 24) matrix->drawRGBBitmap(x, y, (const uint16_t *) bitmap24, bitmapSize, bitmapSize);
      matrix->show();
   
  // Only pan if the display size is smaller than the pixmap
  // but not if the difference is too small or it'll look bad.
  if (bitmapSize-mw>2) {
      if (mw>9) xf += xfc*xfdir;
        if (xf >= 0){ xfdir = -1; updDir = true ; };
      // we don't go negative past right corner, go back positive
        if (xf <= ((mw-bitmapSize) << 4)) { xfdir = 1;  updDir = true ; };
   }
  if (bitmapSize-mh>2) {
      yf += yfc*yfdir;
      // we shouldn't display past left corner, reverse direction.
      if (yf >= 0)                      { yfdir = -1; updDir = true ; };
      if (yf <= ((mh-bitmapSize) << 4)) { yfdir = 1;  updDir = true ; };
   }
  // only bounce a pixmap if it's smaller than the display size
  if (mw>bitmapSize) {
      xf += xfc*xfdir;
      // Deal with bouncing off the 'walls'
      if (xf >= (mw-bitmapSize) << 4) { xfdir = -1; updDir = true ; };
      if (xf <= 0)           { xfdir =  1; updDir = true ; };
  }
  if (mh>bitmapSize) {
      yf += yfc*yfdir;
      if (yf >= (mh-bitmapSize) << 4) { yfdir = -1; updDir = true ; };
      if (yf <= 0)           { yfdir =  1; updDir = true ; };
  }
  
  if (updDir) {
      // Add -1, 0 or 1 but bind result to 1 to 1.
      // Let's take 3 is a minimum speed, otherwise it's too slow.
      xfc = constrain(xfc + random(-1, 2), 3, 16);
      yfc = constrain(yfc + random(-1, 2), 3, 16);
  }
  delay(10);
  }
}

