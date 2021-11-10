//Download Library LiquidCrystal_I2C
#include <LiquidCrystal_I2C.h>
//Inisialisasi pembuatan variable
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 lcd.begin();
}

void loop() {

  float suhu=random(16.1,32.10);

 lcd.clear(); //Untuk Menghapus karakter pada LCD
 lcd.setCursor(0,0); lcd.print("Suhu:");
 lcd.setCursor(5,0); lcd.print(suhu);
 lcd.setCursor(11,0); lcd.print("C");
 delay(1000); //Jeda waktu perulagan seama 1000 mili detik
}
