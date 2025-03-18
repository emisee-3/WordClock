#include "FastLED.h"
#define CLOCKLIGHT 0x000010
#define RANGE(NAME, FROM, TO) void NAME() {for (int i=FROM; i <= TO; i++){leds[i] = CLOCKLIGHT; }} 

void W_ESIST() {
  leds[90] = CLOCKLIGHT;
  leds[91] = CLOCKLIGHT;
  leds[92] = CLOCKLIGHT;
  leds[93] = CLOCKLIGHT;
  leds[94] = CLOCKLIGHT;
}

RANGE(M_FUENF, 86, 89)
RANGE(M_ZEHN, 75, 78)
RANGE(M_ZWANZIG, 79, 85)
RANGE(M_VIERTEL, 64, 70)
RANGE(W_NACH, 57, 60)
RANGE(W_VOR, 61, 63)
RANGE(M_HALB, 53, 56)
RANGE(H_ZWOELF, 48, 52)
RANGE(H_ZWEI, 37, 40)
RANGE(H_EIN, 39, 41)
RANGE(H_EINS, 39, 42)
RANGE(H_SIEBEN, 42, 47)
RANGE(H_DREI, 33, 36)
RANGE(H_FUENF, 28, 31)
RANGE(H_ELF, 17, 19)
RANGE(H_NEUN, 20, 23)
RANGE(H_VIER, 24, 27)
RANGE(H_ACHT, 13, 16)
RANGE(H_ZEHN, 9, 12)
RANGE(H_SECHS, 0, 4)
RANGE(W_UHR, 5, 7)
//void P_EINS() {
//  leds[113].setRGB( R, G, B);  // OL
//}
//void P_ZWEI() {
//  leds[113].setRGB( R, G, B);  //OL
//  leds[112].setRGB( R, G, B);  //OR
//
//}
//void P_DREI() {
//  leds[113].setRGB( R, G, B);  //OL
//  leds[112].setRGB( R, G, B);  //OR
//  leds[111].setRGB( R, G, B);  //UR
//}
//void P_VIER() {
//  leds[112].setRGB( R, G, B);  //OL
//  leds[111].setRGB( R, G, B);  //OR
//  leds[110].setRGB( R, G, B);  //UR
//  leds[113].setRGB( R, G, B);  //UL
//}
//
//
//
//// SECONDS COUNTER MODE
//void L_ZERO(){
//  for (int i=23; i <= 25; i++){
//    leds[i].setRGB( R, G, B);  
//  }
//  leds[43].setRGB( R, G, B);  
//  leds[39].setRGB( R, G, B);  
//  leds[44].setRGB( R, G, B);  
//  leds[47].setRGB( R, G, B);  
//  leds[48].setRGB( R, G, B);  
//  leds[65].setRGB( R, G, B);  
//  leds[61].setRGB( R, G, B);  
//  leds[63].setRGB( R, G, B);  
//  leds[66].setRGB( R, G, B);  
//  leds[67].setRGB( R, G, B);  
//  leds[70].setRGB( R, G, B);  
//  leds[87].setRGB( R, G, B);  
//  leds[83].setRGB( R, G, B);  
//  for (int i=89; i <= 91; i++){
//    leds[i].setRGB( R, G, B);  
//  }
//}
//
//void L_ONE(){
//  leds[24].setRGB( R, G, B);  
//  leds[42].setRGB( R, G, B);  
//  leds[41].setRGB( R, G, B);  
//  leds[46].setRGB( R, G, B);  
//  leds[63].setRGB( R, G, B);  
//  leds[68].setRGB( R, G, B);  
//  leds[85].setRGB( R, G, B);  
//  for (int i=89; i <= 91; i++){
//    leds[i].setRGB( R, G, B);  
//  }  
//}
//void L_TWO(){
//  for (int i=23; i <= 25; i++){
//    leds[i].setRGB( R, G, B);  
//  }
//  leds[43].setRGB( R, G, B);  
//  leds[39].setRGB( R, G, B);  
//  leds[48].setRGB( R, G, B);  
//  leds[62].setRGB( R, G, B);  
//  leds[68].setRGB( R, G, B);  
//  leds[86].setRGB( R, G, B);  
//  for (int i=88; i <= 92; i++){
//    leds[i].setRGB( R, G, B);  
//  } 
//}
//
//void L_THREE(){
//  for (int i=22; i <= 26; i++){
//    leds[i].setRGB( R, G, B);  
//  }
//  leds[40].setRGB( R, G, B);  
//  leds[46].setRGB( R, G, B);  
//  leds[62].setRGB( R, G, B);  
//  leds[70].setRGB( R, G, B);  
//  leds[83].setRGB( R, G, B);  
//  leds[87].setRGB( R, G, B);  
//  for (int i=89; i <= 91; i++){
//    leds[i].setRGB( R, G, B);  
//  }  
//}
//
//void L_FOUR(){
//  leds[25].setRGB( R, G, B);  
//  leds[40].setRGB( R, G, B);  
//  leds[41].setRGB( R, G, B);  
//  leds[45].setRGB( R, G, B);  
//  leds[47].setRGB( R, G, B);  
//  leds[65].setRGB( R, G, B);  
//  leds[62].setRGB( R, G, B);  
//  for (int i=66; i <= 70; i++){
//    leds[i].setRGB( R, G, B);  
//  }
//  leds[84].setRGB( R, G, B);  
//  leds[91].setRGB( R, G, B); 
//  
//}
//
//void L_FIVE(){
//  for (int i=22; i <= 26; i++){
//    leds[i].setRGB( R, G, B);  
//  }
//  leds[43].setRGB( R, G, B);  
//  leds[44].setRGB( R, G, B);  
//  for (int i=62; i <= 65; i++){
//    leds[i].setRGB( R, G, B);  
//  }  
//  leds[70].setRGB( R, G, B);  
//  leds[83].setRGB( R, G, B);  
//  for (int i=89; i <= 91; i++){
//    leds[i].setRGB( R, G, B);  
//  }
//  leds[87].setRGB( R, G, B);  
//}
//
//void R_ZERO(){
//  for (int i=29; i <= 31; i++){
//    leds[i].setRGB( R, G, B);  
//  }
//  leds[37].setRGB( R, G, B);  
//  leds[33].setRGB( R, G, B);  
//  leds[50].setRGB( R, G, B);  
//  leds[53].setRGB( R, G, B);  
//  leds[54].setRGB( R, G, B);  
//  leds[59].setRGB( R, G, B);  
//  leds[57].setRGB( R, G, B);  
//  leds[55].setRGB( R, G, B);  
//  leds[72].setRGB( R, G, B);  
//  leds[73].setRGB( R, G, B);  
//  leds[76].setRGB( R, G, B);  
//  leds[81].setRGB( R, G, B);  
//  leds[77].setRGB( R, G, B);  
//  for (int i=95; i <= 97; i++){
//    leds[i].setRGB( R, G, B);  
//  }
//}
//
//void R_ONE(){
//  leds[30].setRGB( R, G, B);  
//  leds[36].setRGB( R, G, B);  
//  leds[35].setRGB( R, G, B);  
//  leds[52].setRGB( R, G, B);  
//  leds[57].setRGB( R, G, B);  
//  leds[74].setRGB( R, G, B);  
//  leds[79].setRGB( R, G, B);  
//  for (int i=95; i <= 97; i++){
//    leds[i].setRGB( R, G, B);  
//  }
//}
//
//void R_TWO(){
//  for (int i=29; i <= 31; i++){
//    leds[i].setRGB( R, G, B);  
//  }
//  leds[37].setRGB( R, G, B);  
//  leds[33].setRGB( R, G, B);  
//  leds[54].setRGB( R, G, B);  
//  leds[56].setRGB( R, G, B);  
//  leds[74].setRGB( R, G, B);  
//  leds[80].setRGB( R, G, B);  
//  for (int i=94; i <= 98; i++){
//    leds[i].setRGB( R, G, B);  
//  } 
//}
//
//void R_THREE(){
//  for (int i=28; i <= 32; i++){
//    leds[i].setRGB( R, G, B);  
//  }
//  leds[34].setRGB( R, G, B);  
//  leds[52].setRGB( R, G, B);  
//  leds[56].setRGB( R, G, B);  
//  leds[76].setRGB( R, G, B);  
//  leds[77].setRGB( R, G, B);  
//  leds[81].setRGB( R, G, B);  
//  for (int i=95; i <= 97; i++){
//    leds[i].setRGB( R, G, B);  
//  }  
//}
//
//void R_FOUR(){
//  leds[31].setRGB( R, G, B);  
//  leds[34].setRGB( R, G, B);  
//  leds[35].setRGB( R, G, B);  
//  leds[51].setRGB( R, G, B);  
//  leds[53].setRGB( R, G, B);  
//  leds[59].setRGB( R, G, B);  
//  leds[56].setRGB( R, G, B);  
//  for (int i=72; i <= 76; i++){
//    leds[i].setRGB( R, G, B);  
//  }
//  leds[78].setRGB( R, G, B);  
//  leds[97].setRGB( R, G, B); 
//}
//
//void R_FIVE(){
//  for (int i=28; i <= 32; i++){
//    leds[i].setRGB( R, G, B);  
//  }
//  leds[37].setRGB( R, G, B);  
//  leds[50].setRGB( R, G, B);  
//  for (int i=56; i <= 59; i++){
//    leds[i].setRGB( R, G, B);  
//  }  
//  leds[76].setRGB( R, G, B);  
//  leds[77].setRGB( R, G, B);  
//  for (int i=95; i <= 97; i++){
//    leds[i].setRGB( R, G, B);  
//  }
//  leds[81].setRGB( R, G, B);  
//}
//
//void R_SIX(){
//  leds[30].setRGB( R, G, B);  
//  leds[31].setRGB( R, G, B);  
//  leds[36].setRGB( R, G, B);  
//  leds[50].setRGB( R, G, B);  
//  for (int i=56; i <= 59; i++){
//    leds[i].setRGB( R, G, B);  
//  }
//  leds[72].setRGB( R, G, B);  
//  leds[76].setRGB( R, G, B);
//  leds[81].setRGB( R, G, B);  
//  leds[77].setRGB( R, G, B);
//  for (int i=95; i <= 97; i++){
//    leds[i].setRGB( R, G, B);  
//  }
//}
//
//void R_SEVEN(){
//  for (int i=28; i <= 32; i++){
//    leds[i].setRGB( R, G, B);  
//  }
//  leds[33].setRGB( R, G, B);  
//  leds[53].setRGB( R, G, B);
//  leds[57].setRGB( R, G, B);  
//  leds[73].setRGB( R, G, B);
//  leds[80].setRGB( R, G, B);  
//  leds[95].setRGB( R, G, B);
//}
//
//void R_EIGHT(){
//  for (int i=29; i <= 31; i++){
//    leds[i].setRGB( R, G, B);  
//  }
//  leds[37].setRGB( R, G, B);  
//  leds[33].setRGB( R, G, B);
//  leds[50].setRGB( R, G, B);  
//  leds[54].setRGB( R, G, B);
//  for (int i=56; i <= 58; i++){
//    leds[i].setRGB( R, G, B);  
//  }
//  leds[72].setRGB( R, G, B);  
//  leds[76].setRGB( R, G, B);
//  leds[81].setRGB( R, G, B);  
//  leds[77].setRGB( R, G, B);
//  for (int i=95; i <= 97; i++){
//    leds[i].setRGB( R, G, B);  
//  }
//}
//
//
//void R_NINE(){
//  for (int i=29; i <= 31; i++){
//    leds[i].setRGB( R, G, B);  
//  }
//  leds[37].setRGB( R, G, B);  
//  leds[33].setRGB( R, G, B);
//  leds[50].setRGB( R, G, B);  
//  leds[54].setRGB( R, G, B);
//  for (int i=55; i <= 58; i++){
//    leds[i].setRGB( R, G, B);  
//  }
//  leds[76].setRGB( R, G, B);  
//  leds[78].setRGB( R, G, B);
//  leds[95].setRGB( R, G, B);  
//  leds[96].setRGB( R, G, B);
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
