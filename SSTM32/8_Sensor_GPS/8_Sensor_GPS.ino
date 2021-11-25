//Inisialisasi
#include <TinyGPS++.h>
int GPSBaud=9600;

//Tiny GPS
TinyGPSPlus gps;
String latitude, longitude;

void setup() {
 Serial.begin(9600);
 Serial2.begin(115200);
}

void loop() {
  // Baca
  while ( Serial2.available() > 0){
    gps.encode(Serial2.read());
  }
  if (gps.location.isValid()){
    latitude = String(gps.location.lat(), 6);
    longitude = String(gps.location.lng(), 6);
    String link = ("www.google.com/maps/place/" + String(latitude) + "," + String(longitude));
    Serial.println(link);
    delay(500);
  }
}
