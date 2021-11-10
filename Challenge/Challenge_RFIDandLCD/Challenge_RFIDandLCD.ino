//Inisialisasi
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

String uidString;
int sensor=A0;
int buzzer=5;
int masuk=0;
int ledR=2;
int ledK=3;
int ledH=4;

//Servo
int servo=6;
Servo palang;


#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instace

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  SPI.begin(); // initiate SPI bus
  lcd.begin();
  mfrc522.PCD_Init();  //initiate MFRC522
  buzoke();


//  palang.attach(servo)
//  palang.write(0);
  
  pinMode(ledR,OUTPUT);
  pinMode(ledK, OUTPUT);
  pinMode(ledH, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(ledR, HIGH);
  digitalWrite(ledK, LOW);
  digitalWrite(ledH, LOW);
  tempel();
}

void loop() {
  int bacaSensor=digitalRead(sensor);
  
  if(mfrc522.PICC_IsNewCardPresent()) {
    readRFID();
    if( uidString == "1ATCIE9P80" && masuk == 0){
      masuk=1;
      buzoke();
      berhasilmasuk();
      digitalWrite(ledR, LOW);
      digitalWrite(ledK, HIGH);
      delay(500);
      digitalWrite(ledK, LOW);
      digitalWrite(ledH, HIGH);
    } else if ( uidString != "1ATCIE9P80" and masuk == 0){
      buzgaoke();
      digitalWrite(ledR, HIGH);
      digitalWrite(ledK, LOW);
      digitalWrite(ledH, LOW);
      kartugagal();
      delay(800);
      tempel();
    }
  } 

  if (bacaSensor == 0 && masuk==1){
    masuk=0;
    udahmasuk();
    delay(800);
    digitalWrite(ledH, LOW);
    digitalWrite(ledK, HIGH);
    delay(500);
    digitalWrite(ledK, LOW);
    digitalWrite(ledR, HIGH);
    palangtutup();
    delay(1000);
    tempel();
  }
}

//FungsiTambahan
void readRFID(){
  mfrc522.PICC_ReadCardSerial();
  //pembatas bisa di ubah sesuai keinginan,disini yang digunakan "U"
  uidString=String(mfrc522.uid.uidByte[0], HEX)+"T"+
  String(mfrc522.uid.uidByte[1], HEX) +"I"+
  String(mfrc522.uid.uidByte[2], HEX) +"P"+
  String(mfrc522.uid.uidByte[3], HEX);
  uidString.toUpperCase();
}

//LCD

void kartugagal(){
  lcd.clear();
  lcd.setCursor(3,0); lcd.print("Kartu");
  lcd.setCursor(9,0); lcd.print("Gagal");
}

void udahmasuk(){
  lcd.clear();
  lcd.setCursor(3,0); lcd.print("Sudah");
  lcd.setCursor(9,0); lcd.print("Masuk");
}

void berhasilmasuk(){
  lcd.clear();
  lcd.setCursor(5,0); lcd.print("Berhasil");
  delay(800);
  lcd.clear();
  lcd.setCursor(4,0); lcd.print("Silahkan");
  lcd.setCursor(6,1); lcd.print("Masuk");
}

void tempel (){
  lcd.clear();
  lcd.setCursor(4,0); lcd.print("Tempelkan");
  lcd.setCursor(6,1); lcd.print("Kartu!");
}

void palangtutup(){
  lcd.clear();
  lcd.setCursor(5,0); lcd.print("Palang");
  lcd.setCursor(4,1); lcd.print("Ditutup");   
}

//Buzzer

void buzoke(){
  digitalWrite(buzzer,HIGH);
  delay(50);
  digitalWrite(buzzer,LOW);
  delay(50);
  digitalWrite(buzzer,HIGH);
  delay(50);
  digitalWrite(buzzer,LOW);
}
void buzgaoke(){
  digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(buzzer,LOW);
}
