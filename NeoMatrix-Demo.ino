                      

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
  
 load_panel(LED_RED_HIGH, 50);
 load_panel(LED_GREEN_HIGH, 50);
 load_panel(LED_BLUE_HIGH, 50);
 unload_panel(LED_BLACK, 50);                    
 colorallfill(LED_GREEN_HIGH, 500);           
 colorallfill(LED_ORANGE_HIGH, 500);           
 colorallfill(LED_CYAN_HIGH, 500);           
 colorallfill(LED_WHITE_HIGH, 500);           
 matrix->clear();
         
 // Fills the NeoMatrix 8X8 panel in a spiral then revers's it 
 spiral_colorWipe(LED_RED_HIGH, 50); 
 reverse_spiral_colorWipe(LED_GREEN_MEDIUM, 50); 
 onepixel_spiral_colorWipe(LED_BLUE_HIGH, 50); 
 reverse_spiral_colorWipe(LED_GREEN_HIGH, 50); 
 spiral_colorWipe(LED_ORANGE_HIGH, 50); 
 reverse_spiral_colorWipe(LED_CYAN_HIGH, 50); 
 onepixel_spiral_colorWipe(LED_PURPLE_HIGH, 50); 
 reverse_spiral_colorWipe(LED_ORANGE_HIGH, 50);         
 colorallfill(LED_BLACK, 250);
 matrix->clear();        

 // Fills the NeoMatrix 8X8 panel using one 4X4 minimatrix at a time in the 8X8 panel
 fourmatrixes_colorWipe(LED_RED_HIGH, 50);
 fourmatrixes_colorWipe(LED_GREEN_HIGH, 50); 
 fourmatrixes_colorWipe(LED_ORANGE_HIGH, 50); 
 matrix->clear(); 
             
 // Fills the NeoMatrix 8X8 panel using all of the 4X4 minimatrix at the same time in the 8X8 panel
 fourmatrixes_same_colorWipe(LED_RED_HIGH, 50); 
 fourmatrixes_same_colorWipe(LED_GREEN_HIGH, 50);
 fourmatrixes_same_colorWipe(LED_ORANGE_HIGH, 50); 
 matrix->clear();
    
/*            
 // Fills the NeoMatrix 8X8 panel with with split spiral one full box at a time  
 split_spiral_colorWipe(matrix->Color(0, 50, 0), 100); //red reverse spiral   
 split_spiral_colorWipe(matrix->Color(50, 0, 0), 100); //blue reverse spiral
 split_spiral_colorWipe(matrix->Color(50, 50, 0), 100); //red reverse spiral 
 colorallfill(matrix->Color(0, 0, 0), 250);          // clears color
*/     

}

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
void spiral_colorWipe(int c, uint16_t wait) {    
  for(uint16_t j=0; j<4; j++) {
   uint16_t x=boxtotalarray[j];
    for(uint16_t k=0; k<x; k++) {
      matrix->setPixelColor(bigboxarray[j][k], c);     
      matrix->show();
      delay(wait);
     }
   }
}

// test fills color into NeoMatrix 8X8 panel with in a spiral -  one neopixel after the other
void test_spiral_colorWipe(int c, uint16_t wait) {    
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
void reverse_spiral_colorWipe(int c, uint16_t wait) {    
  for(uint16_t j=0; j<4; j++) {
    uint16_t x=revboxtotalarray[j];
    for(uint16_t k=0; k<x; k++) {
      matrix->setPixelColor(revbigboxarray[j][k], c);      
      matrix->show();
      delay(wait);
     }
  }
}

// Fills the each of 4 seperate 4X4 matrixes in the NeoMatrix 8X8 panel with in a spiral -  one neopixel after the other
void fourmatrixes_colorWipe(int c, uint16_t wait) {    
   for(uint16_t j=0; j<4; j++) {
    for(uint16_t k=0; k<16; k++) {
      matrix->setPixelColor(bigfourarray[j][k], c);     
      matrix->show();
      delay(wait);
      }
  }
}  

// Fills the all of the 4 seperate 4X4 matrixes in the NeoMatrix 8X8 panel in a spiral -  one neopixel after the other
void fourmatrixes_same_colorWipe(int c, uint16_t wait) { 
  for(uint16_t k=0; k<16; k++) {
      matrix->setPixelColor(bigfourarray[0][k], c);    
      matrix->setPixelColor(bigfourarray[1][k], c); 
      matrix->setPixelColor(bigfourarray[2][k], c); 
      matrix->setPixelColor(bigfourarray[3][k], c);  
      matrix->show();
      delay(wait);
    }
}  

//Fills the NeoMatrix 8X8 panel half a side at a time together
void split_spiral_colorWipe(int c, uint16_t wait) {    
  for(uint16_t j=0; j<8; j+=2) {
    uint16_t x=splitboxtotalarray[j];
    for(uint16_t k=0; k<x; k++) {
      matrix->setPixelColor(splitbigboxarray[j][k], c);  
      matrix->setPixelColor(splitbigboxarray[j+1][k], c);    
      matrix->show();
      delay(wait);
      }
  }
}

// Fills the NeoMatrix 8X8 panel in a spiral -  one neopixel after the other with only one neoPixel light at a time
void onepixel_spiral_colorWipe(int c, uint16_t wait) {    
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
void reverse_onepixel_spiral_colorWipe(int c, uint16_t wait) {    
  
  for(uint16_t j=0; j<4; j++) {
    uint16_t x=revboxtotalarray[j];
    for(uint16_t k=0; k<x; k++) {
      matrix->setPixelColor(revbigboxarray[j][k], c);      
      matrix->show();
      delay(wait);
      matrix->setPixelColor(revbigboxarray[j][k], 0);      
      matrix->show();
     }
  }
}

// Fills the NeoMatrix 8X8 panel in a squares -  one square after the other
void box_colorWipe(int c, uint16_t wait) {    
  
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
void fullallbox_colorWipe(int c, uint16_t wait, uint8_t* boxarray, int x) { // Note: boxarray is the name of the array being used.  x is the number of members in the array being used.
  
 for(uint16_t i=0; i<x; i++) {
    matrix->setPixelColor(boxarray[i], c);     
    }   
    matrix->show();
    delay(wait);   
} 

// Fills the NeoMatrix 8X8 panel with all of the NeoPixes at one time 
void colorallfill(int c, uint16_t wait) {  
  for(uint16_t i=0; i<matrix->numPixels(); i++) {
    matrix->setPixelColor(i, c);      
    }       
    matrix->show();
    delay(wait);   
}      

