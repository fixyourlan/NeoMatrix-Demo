                      

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

// the setup routine runs once when you press reset:
void setup() {
    Serial.begin(115200);
    matrix->begin();
    matrix->setBrightness(BRIGHTNESS);
    // Test full bright of all LEDs. If brightness is too high
    // for your current limit (i.e. USB), decrease it.
//    matrix->fillScreen(LED_WHITE_MEDIUM);
//    matrix->show();
//    delay(100);
    matrix->clear();
}

// the loop routine runs over and over again forever;
void loop() {
// rainbowCycle(50); 
 load_panel(LED_RED_HIGH, 50);
 unload_panel(LED_GREEN_HIGH, 50); 
 load_panel(LED_ORANGE_HIGH, 10);
 unload_panel(LED_BLACK, 10);                    
 color_all_fill(LED_RED_HIGH, 500);           
 color_all_fill(LED_GREEN_HIGH, 500);           
 color_all_fill(LED_ORANGE_HIGH, 500);           
 matrix->clear();
         
 // Fills the NeoMatrix 8X8 panel in a spiral then revers's it 
 spiral_color_wipe(LED_RED_HIGH, 50); 
 reverse_spiral_color_wipe(LED_GREEN_MEDIUM, 50); 
 one_pixel_spiral_color_wipe(LED_PURPLE_HIGH, 20); 
 matrix->clear();        

 // Fills the NeoMatrix 8X8 panel using one 4X4 minimatrix at a time in the 8X8 panel
 four_matrixes_color_wipe(LED_RED_HIGH, 50);
 reverse_four_matrixes_color_wipe(LED_GREEN_HIGH, 50); 
 one_pixel_four_matrixes_color_wipe(LED_ORANGE_HIGH, 50); 
 matrix->clear(); 
             
 // Fills the NeoMatrix 8X8 panel using all of the 4X4 minimatrix 
 // at the same time in the 8X8 panel
 four_matrixes_same_color_wipe(LED_RED_HIGH, 50); 
 reverse_four_matrixes_same_color_wipe(LED_GREEN_HIGH, 50);
 one_pixel_four_matrixes_same_color_wipe(LED_RED_HIGH, 50); 
 four_matrixes_same_color_wipe(LED_ORANGE_HIGH, 50); 
 reverse_one_pixel_four_matrixes_same_color_wipe(LED_GREEN_HIGH, 50);
 matrix->clear();

 split_spiral_color_wipe(LED_RED_HIGH, 50);
 reverse_split_spiral_color_wipe(LED_GREEN_HIGH, 50);
 one_pixel_split_spiral_color_wipe(LED_RED_HIGH, 50);
 reverse_split_spiral_color_wipe(LED_GREEN_HIGH, 25);
 one_pixel_split_spiral_color_wipe(LED_RED_HIGH, 25);
 reverse_one_pixel_split_spiral_color_wipe(LED_RED_HIGH, 10);
 one_pixel_split_spiral_color_wipe(LED_GREEN_HIGH, 5);
 reverse_one_pixel_split_spiral_color_wipe(LED_RED_HIGH, 5);

 matrix->clear();

} // End of main Loop

// Functions for loop -----------------------------------------------------------------

// Fills the NeoMatrix 8X8 panel by the numbers in order -  one neopixel after the other
void load_panel(int c, uint16_t wait){    
   for(uint16_t i=0; i<matrix->numPixels(); i++) {
      matrix->setPixelColor(i, c);      
      matrix->show();
      delay(wait);
      }
}

void unload_panel(int c, uint16_t wait){    
  for(uint16_t i=matrix->numPixels(); i>0; i--) {
      matrix->setPixelColor(i, c);      
      matrix->show();
      delay(wait);
     }
}

// Fills the NeoMatrix 8X8 panel with in a spiral -  one neopixel after the other
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

// Fills the NeoMatrix 8X8 panel with in a reverse spiral -  one neopixel after the other
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

// Fills the each of 4 seperate 4X4 matrixes in the NeoMatrix 8X8 panel with in a spiral -  one neopixel after the other
void four_matrixes_color_wipe(int c, uint16_t wait) {    
   for(uint16_t j=0; j<4; j++) {
    for(uint16_t k=0; k<16; k++) {
      matrix->setPixelColor(bigfourarray[j][k], c);     
      matrix->show();
      delay(wait);
      }
  }
}  
// Fills the each of 4 seperate 4X4 matrixes in the NeoMatrix 8X8 panel with in a spiral -  one neopixel after the other
void reverse_four_matrixes_color_wipe(int c, uint16_t wait) {    
   for(int j=3; j>=0; j--) {
    for(int k=15; k>=0; k--) {
      matrix->setPixelColor(bigfourarray[j][k], c);     
      matrix->show();
      delay(wait);
      }
  }
} 
// Fills the each of 4 seperate 4X4 matrixes in the NeoMatrix 8X8 panel with in a spiral -  one neopixel after the other
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
// Fills the each of 4 seperate 4X4 matrixes in the NeoMatrix 8X8 panel with in a spiral -  one neopixel after the other
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
// Fills the all of the 4 seperate 4X4 matrixes in the 
// NeoMatrix 8X8 panel in a spiral -  one neopixel at a time in each cube
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
// Fills the all of the 4 seperate 4X4 matrixes in the 
// NeoMatrix 8X8 panel in a spiral -  one neopixel at a time in each cube
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
// NeoMatrix 8X8 panel in a spiral -  one neopixel after another in each cube
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
// Fills the all of the 4 seperate 4X4 matrixes in the 
// NeoMatrix 8X8 panel in a spiral -  one neopixel after another in each cube
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
 
//Fills the NeoMatrix 8X8 panel half a side at a time together
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
//Fills the NeoMatrix 8X8 panel half a side at a time together in reverse
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

//Fills the NeoMatrix 8X8 panel half a side at a time together
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
//Fills the NeoMatrix 8X8 panel half a side at a time together in reverse
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
// Fills the NeoMatrix 8X8 panel in a spiral -  one neopixel after the other with only one neoPixel light at a time
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

// Fills the NeoMatrix 8X8 panel in a spiral -  one neopixel after the other with only one neoPixel light at a time
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

// Fills the NeoMatrix 8X8 panel in a squares -  one square after the other
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
