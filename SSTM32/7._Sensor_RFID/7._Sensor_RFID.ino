/*/
 * A9  to RX USBTTL
 * A10 to TX USBTTL
 * PB0 to RESET
 * PB1 to SDA / SS
 * PA5 to CLK
 * PA6 to MISO
 * PA7 to MOSI
 * Tekan Reset sebelum Upload
 * Pilih Board    :fake STM32F10 
 * Upload methode :Serial
 */
//Download dan masukan Library
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>

//Inisialisasi pembuatan variable
#define SS_PIN  PA4 //SDA
#define RST_PIN PB0  //RESET

MFRC522 mfrc522(SS_PIN, RST_PIN); 

//Servo
const int pinSer=PA8;
Servo palang;

//Buz
const int pinBuz=PA3;

//LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

//but
const int pinBut=PB1;
const int pinBut2=PB10;

//  Flag
  int masuk=0;
  int rfid=0;

void setup() {
  Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer

//  RFID
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522

//  Servo
  palang.attach(pinSer);
  palang.write(90);

//  Buzz
  pinMode(pinBuz, OUTPUT);
  digitalWrite(pinBuz, LOW);
  Bsukses();
//but
  pinMode(pinBut, INPUT);
  pinMode(pinBut2, INPUT);

//  LCD
  lcd.begin();
  ltempel();

}

void loop() {
//  Baca
   int bacaBut=digitalRead(pinBut);
   int bacaBut2=digitalRead(pinBut2);
   
   
  Serial.println(String(bacaIR) + " | masuk : " + String(masuk));
  

//  Logika

  if (bacaBut == 1 and masuk == 1) {
    masuk=0;
    llewat();
    stutup();
    ltempel();
    delay(300);
   }

  if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
  if ( ! mfrc522.PICC_ReadCardSerial()) {return;}

  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "" : ""));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  if (content == "2AA5B715" && masuk == 0) {
    masuk=1;
    Bsukses();
    lmasuk();
    sbuka();
    
    delay(300);
   }else if ( masuk == 0 ){
    lkartugagal();
    Bgagal();
    ltempel();
    stutup();
   }
}

//Servo
void sbuka(){
  palang.write(0);
}

void stutup(){
  palang.write(90);
}


//BUzzer
void Bsukses(){
  digitalWrite(pinBuz, HIGH);
  delay(50);
  digitalWrite(pinBuz, LOW);
  delay(50);
  digitalWrite(pinBuz, HIGH);
  delay(50);
  digitalWrite(pinBuz, LOW);
}

void Bgagal(){
  digitalWrite(pinBuz, HIGH);
  delay(800);
  digitalWrite(pinBuz, LOW);
}

//LCD
void lkartugagal (){
  lcd.clear();
  lcd.setCursor(6,0); lcd.print("Kartu");
  lcd.setCursor(6,1); lcd.print("Gagal");
}

void llewat (){
  lcd.clear();
  lcd.setCursor(5,0); lcd.print("Sudah");
  lcd.setCursor(5,1); lcd.print("Lewat");
  delay(800);
  lcd.setCursor(4,0);lcd.print("Palang");
  lcd.setCursor(3,1);lcd.print("Ditutup");
  delay(800);
}

void lmasuk(){
  lcd.clear();
  lcd.setCursor(3,0); lcd.print("Berhasil");
  delay(800);
  lcd.clear();
  lcd.setCursor(3,0); lcd.print("Silahkan");
  lcd.setCursor(6,1); lcd.print("Masuk");
}


void ltempel(){
  lcd.clear();
  lcd.setCursor(3,0); lcd.print("Tempelkan");
  lcd.setCursor(6,1); lcd.print("Kartu!");
}
