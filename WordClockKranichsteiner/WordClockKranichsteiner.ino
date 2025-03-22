/*
LEDs WS2812B
 Copy of the Biegert&Funk QlockTwo reprogramming by volvodani. 
 Licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
 Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file 
 except in compliance with the License.  You may obtain a copy of the License at
 http://www.apache.org/licenses/LICENSE-2.0
 Unless required by applicable law or agreed to in writing, software distributed under the 
 License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, 
 either express or implied. See the License for the specific language governing permissions 
 and limitations under the License.
 */

#include <Wire.h>
#include "FastLED.h"
#include <avr/wdt.h>


#define RTC_ADDRESS 0x68       // I2C Address of RTC 0x68
#define RTCIN 4                // SQW Output of RTC connected here
#define s[NUM_LEDS];


#define DATA_PIN     5
#define DAYLIGHT_SAVING 7
#define NUM_LEDS    100
#define CHIPSET     SK6812

CRGB leds[NUM_LEDS];

//unsigned long ptime;
//unsigned long start;
//boolean druck=false;
//boolean ldruck=true;
//boolean M_minus=false;
//boolean FM_minus=true;
//boolean M_plus=false;
//boolean FM_plus=true;
//boolean M_sek=false;
//boolean FM_sek=true;
////boolean tasterlesen=true;
boolean update,last=true;
boolean sec=false;
boolean lsec=false;
boolean dl_sv=false;
//boolean save,one=false;
//boolean Minus,Plus=false;
//boolean once=false;
//boolean done=false;
//boolean M_timeout=false;
//byte setmode=0;
//byte timeout=0;
////byte lm=0;                                  // 0=Normal 1=Display Seconds 2=Set minutes 3=Set hours
////byte lCase=0;
byte mm,hh,hhdisplay,mmset,mm5er,lmm5er=0;                // Save Variables for time
short int ss, secLookup = 0;
byte secDelay = 2;
short int lookupPeriode = 60;
bool debugging = 0;
//byte R=0,G=0,B=0;                            // Farbe für den Start alles weis
//byte Rpointer,Gpointer,Bpointer;
//byte PWMArray[23]={
//  2,7,10,15,20,25,30,35,40,50,60,70,80,90,100,120,140,160,180,200,220,240,255};


void setup() {
  wdt_enable(WDTO_2S);
  pinMode(RTCIN,INPUT);                          // SQW Output of RTC connected here
    pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(RTCIN,HIGH);
  FastLED.addLeds<SK6812, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
   pinMode(DAYLIGHT_SAVING, INPUT);

  //beginn der seriellen Kommunikation mit 9600baud
  if (debugging){
    Serial.begin(9600);
  }
  Wire.begin();                                  // Start I2C Kommunikation
  Wire.beginTransmission(RTC_ADDRESS);           // Beginn Kommunikation auf  Adresse 0x68 
  Wire.write(0x0E);                               // Pointer auf Control Register 0x07   
  Wire.write(0x00);                               // Controlbyte for RTC to set the sqw Output to 1Hz  
  Wire.endTransmission();                        // Beenden der I2C Kommunitkation
  update=true;
  TimeRead();
  RTC_Start();
  ss = ss + 60*(mm%5);
  if (ss>=secDelay){
    secLookup = (ss-secDelay)%lookupPeriode;
  }else{
    secLookup = lookupPeriode -(secDelay-ss);
  }
  }


// Start Main Loop
void loop() {
  wdt_reset();                      // Watchdog timer falls sich der Controller mal aufhängt
  sec=digitalRead(RTCIN);           // Read the RTC SQWPulse 
  digitalWrite(LED_BUILTIN,sec);
  if (sec==true && lsec==false){
    ++secLookup;                                          // Sekunden Zähler aufadieren
    if (debugging){
      char timestamp[15];
      sprintf(timestamp,"Es ist %02d:%02d:%02d",hh,mm5er,ss);
      Serial.println(timestamp);
      Serial.println(secLookup);
    } 
  if (secLookup==lookupPeriode){                                   // Bei 60 Sekunden eine Minute weiter
      secLookup=0;
      mm5er=mm5er+lookupPeriode/60;
      if(debugging){
        Serial.println(mm5er);
        Serial.println(lmm5er);
      }
      
    }
    lsec=true;  
  }

    if(mm5er!=lmm5er||update==true){                      // Wenn die Miunten nicht gleich der Minuten letzten durchlauf sind oder der update Merker gesetzt  
      FastLED.clear();
      TimeRead();                                   // RTC auslesen
      if (debugging){
        char timestamp[15];
        sprintf(timestamp,"Es ist jetzt %02d:%02d:%02d",hh,mm,ss);
        Serial.println(timestamp);
      }
     if (digitalRead(DAYLIGHT_SAVING)){
      hh++;
      if (hh == 24){
        hh = 0;
      }
     }
      update=false; 
      mm5er=mm-mm%5;                           // den 5er Teiler berechen 0,5,10,15,20....55 etc.
      ss = ss + 60*(mm%5);
      if (ss>=secDelay){
        secLookup = (ss-secDelay)%lookupPeriode;
      }else{
        secLookup = lookupPeriode -(secDelay-ss);
      }
      if (debugging){
        char timestamp[15];
        sprintf(timestamp,"Es ist jetzt %02d:%02d:%02d",hh,mm5er,ss);
        Serial.println(timestamp);
      }
      //hhdisplay=hh-12*(hh/12);            
      /*  Zeitanzeigeausgabe in Worten */ 
      if (mm5er==0||mm5er==30){
        W_ESIST();
      }
      if (mm5er==5||mm5er==25||mm5er==35||mm5er==55){
        M_FUENF();
      }
      if (mm5er==10||mm5er==50){
        M_ZEHN();
      }
      if (mm5er==15||mm5er==45){
        M_VIERTEL();
      }
      if (mm5er==20||mm5er==40){
        M_ZWANZIG();
      }        
      if (mm5er==25||mm5er==30||mm5er==35){
        M_HALB();
      }
      if (mm5er==0){  
        W_UHR();
      }
      if (mm5er==5||mm5er==10||mm5er==15||mm5er==20||mm5er==35){
        W_NACH();
      }
      if (mm5er==25||mm5er==40||mm5er==45||mm5er==50||mm5er==55){
        W_VOR();
      }
      hhdisplay=hh;
      if (mm5er>=25){                                          // ab der 25 Minuten ist es immer "vor" der nächsetn Stunde 
        if (hh==0||hh==12){                                 // bei 12 Uhr vor "Ein" Uhr 
          hhdisplay=1;
        }
        else
          hhdisplay=hh+1;
      }
      if ((hhdisplay==1||hhdisplay==13)&&mm5er==0) H_EIN();               // Bei Voller Stunde ohne Minute "Ein" Uhr
      else if (hhdisplay==1||hhdisplay==13) H_EINS();                   // Normale "Stunden" Auswahl
      else if (hhdisplay==2||hhdisplay==14) H_ZWEI();
      else if (hhdisplay==3||hhdisplay==15) H_DREI();
      else if (hhdisplay==4||hhdisplay==16) H_VIER(); 
      else if (hhdisplay==5||hhdisplay==17) H_FUENF();
      else if (hhdisplay==6||hhdisplay==18) H_SECHS(); 
      else if (hhdisplay==7||hhdisplay==19) H_SIEBEN(); 
      else if (hhdisplay==8||hhdisplay==20) H_ACHT();  
      else if (hhdisplay==9||hhdisplay==21) H_NEUN();
      else if (hhdisplay==10||hhdisplay==22) H_ZEHN();
      else if (hhdisplay==11||hhdisplay==23) H_ELF();
      else if (hhdisplay==12||hhdisplay==24||hhdisplay==0) H_ZWOELF();

    lmm5er=mm5er;
    FastLED.show();
  }
  if (sec==false && lsec==true){                          // Flankenerkenung des Sekunden Impusles
    lsec=false;

}
}
// End Main Loop

