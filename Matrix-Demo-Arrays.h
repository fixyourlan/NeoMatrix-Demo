
   // arrays for forward spiral
      int x;  // number of elements in an array
      uint8_t boxarray1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 23, 24, 39, 40, 55, 56, 57, 58, 59, 60, 61, 62, 63, 48, 47, 32, 31, 16, 15};
      uint8_t boxarray2[] = {14, 13, 12, 11, 10, 9, 22, 25, 38, 41, 54, 53, 52, 51, 50, 49, 46, 33, 30, 17};
      uint8_t boxarray3[] = {18, 19, 20, 21, 26, 37, 42, 43, 44, 45, 34, 29};
      uint8_t boxarray4[] = {28, 27, 36, 35};
   // array of the number of elements in each array above
      int boxtotalarray[] = {28, 20, 12, 4}; 
   // array of the above arrays 
      const unsigned char * bigboxarray[] ={boxarray1, boxarray2, boxarray3, boxarray4}; 

  // arrays for split box
     uint8_t splitboxarray1[] = { 0,  1,  2,  3,  4,  5,  6,  7,  8, 23, 24, 25, 26, 27, 28, 29, 30, 31, 16, 15};
     uint8_t splitboxarray2[] = {56, 57, 58, 59, 60, 61, 62, 63, 48, 47, 32, 33, 34, 35, 36, 37, 38, 39, 40, 55};
     uint8_t splitboxarray3[] = {14, 13, 12, 11, 10, 9};
     uint8_t splitboxarray4[] = {54, 53, 52, 51, 50, 49};
     uint8_t splitboxarray5[] = {22, 21, 20, 19, 18, 17};
     uint8_t splitboxarray6[] = {46, 45, 44, 43, 42, 41};
  // array of the number of elements in each array above
     uint8_t splitboxtotalarray[] = {20, 20, 6, 6, 6, 6};
  // array of the above arrays 
     const unsigned char * splitbigboxarray[] ={splitboxarray1, splitboxarray2, splitboxarray3, splitboxarray4, splitboxarray5, splitboxarray6}; 
 
   // 4X4 boxes arrays 
     uint8_t fourarray1[]= {0, 1, 2, 3, 12, 19, 28, 29, 30, 31, 16, 15, 14, 13, 18, 17};
     uint8_t fourarray2[]= {4, 5, 6, 7,  8, 23, 24, 25, 26, 27, 20, 11, 10,  9, 22, 21};
     uint8_t fourarray3[]= {32, 33, 34, 35, 44, 51, 60, 61, 62, 63, 48, 47, 46, 45, 50, 49};
     uint8_t fourarray4[]= {36, 37, 38, 39, 40, 55, 56, 57, 58, 59, 52, 43, 42, 41, 54, 53};
  // array of the above arrays
     const unsigned char * bigfourarray[]={fourarray1, fourarray2, fourarray3, fourarray4};
   
