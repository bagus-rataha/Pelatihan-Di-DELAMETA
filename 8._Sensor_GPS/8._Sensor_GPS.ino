//Download dan masukan Library TinyGPS++
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
//Inisialisasi pembuatan variable
SoftwareSerial serial_gps(6, 7); //Komunikasi UART ke GPS
TinyGPSPlus gps;
String latitude, longitude;
void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 serial_gps.begin(9600);
 Serial.println("GPS Mulai");
}
void loop() {
 //Program yang akan dijalankan berulang-ulang
 while(serial_gps.available()) {
 gps.encode(serial_gps.read());
 }
 if(gps.location.isUpdated()) {
 latitude = String(gps.location.lat(),6);
 longitude = String(gps.location.lng(),6);
 String link = "www.google.com/maps/place/" + String(latitude) + "," + String(longitude) ;
 Serial.println(link);
 // delay(2000);
 }
 delay(500); //Jeda waktu perulagan seama 500 mili detik
}
