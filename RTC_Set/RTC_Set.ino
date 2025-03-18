#include <Wire.h>
#include <avr/wdt.h>

#define RTC_ADDRESS 0x68       // I2C Address of RTC 0x68
#define RTCIN 4                // SQW Output of RTC connected here

//Variablen für die Werte aus Datum und Uhrzeit
int tag, monat, jahr;
int stunde, minute, sekunde;
//Array mit den abkürzungen für die Monate
const String months[12] = {"Jan", "Feb", "Mar", "Apr","May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};


void setup() {
  Serial.begin(9600);
Serial.println("Serial port open");
    //Kommunikation über die Wire.h bibliothek beginnen.   
  Wire.begin(); 
  //parsen des Datums
  parseDate(__DATE__);
  //parsen der Uhrzeit
  parseTime(__TIME__);
  //Ausgeben des Zeitstempels auf dem seriellen Monitor.
  rtcWriteTime();
  Serial.print(stunde);
  Serial.print(":");
  Serial.print(minute);
  Serial.print(":");
  Serial.println(sekunde);

}


void loop() {}

void parseDate(String date){
  String mo = date.substring(0,3);
  String t = date.substring(4,6);
  String j = date.substring(7);
  tag = t.toInt();
  
  for(int i=0;i<=11;i++){
    String month = months[i];
    if(mo == month){
      monat = i;
      //Da Arrays bei 0 beginnen müssen wir dem Zähler noch einen Wert dazu addieren.
      ++monat;
      break;
    }
  }
  jahr = j.toInt();
}
void parseTime(String time){
  String st = time.substring(0,2);
  String mi = time.substring(3,5);
  String se = time.substring(6);
  stunde = st.toInt();
  minute = mi.toInt();
  sekunde = se.toInt();  
}
//Funktion zum schreiben / setzen der Uhrzeit.
void rtcWriteTime(){
  Wire.beginTransmission(RTC_ADDRESS);
  Wire.write(0); // Der Wert 0 aktiviert das RTC Modul.
  Wire.write(decToBcd(sekunde));    
  Wire.write(decToBcd(minute));
  Wire.write(decToBcd(stunde));                                  
  Wire.write(decToBcd(0)); // Wochentag unberücksichtigt
  Wire.write(decToBcd(tag));
  Wire.write(decToBcd(monat));
  Wire.write(decToBcd(jahr-2000));  
  Wire.endTransmission();  
}

//Convertiert Dezimalzeichen in binäre Zeichen.
byte decToBcd(byte val){
  return ( (val/10*16) + (val%10) );
}
