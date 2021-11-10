//Inisialisasi
#include <SPI.h>
#include <MFRC522.h>

String uidString;
int sensor=A0;
int buzzer=5;
int masuk=0;
int ledR=2;
int ledK=3;
int ledH=4;

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instace

void setup() {
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  SPI.begin(); // initiate SPI bus
  mfrc522.PCD_Init();  //initiate MFRC522
  oke();
  pinMode(ledR,OUTPUT);
  pinMode(ledK, OUTPUT);
  pinMode(ledH, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(ledR, HIGH);
  digitalWrite(ledK, LOW);
  digitalWrite(ledH, LOW);
  Serial.println("Tempelkan Kartu!");
}

void loop() {
  
  int bacaSensor=digitalRead(sensor);
  
  if(mfrc522.PICC_IsNewCardPresent()) {
    readRFID();
    if(uidString=="1ATCIE9P80" && masuk == 0){
      masuk=1;
      Serial.println("BERHASIL");
      Serial.println("Silahkan Masuk");
      oke();
      digitalWrite(ledR, LOW);
      digitalWrite(ledK, HIGH);
      delay(800);
      digitalWrite(ledK, LOW);
      digitalWrite(ledH, HIGH);
    } else if (masuk == 0){
      Serial.println("Kartu Gagal!");
      Serial.println("Tempelkan Kartu!");
      digitalWrite(ledR, HIGH);
      digitalWrite(ledK, LOW);
      digitalWrite(ledH, LOW);
      gaoke();
    }
  }

  if (bacaSensor ==0 && masuk==1){
    masuk=0;
    Serial.println("Sudah Masuk");
    delay(800);
    digitalWrite(ledH, LOW);
    digitalWrite(ledK, HIGH);
    delay(800);
    digitalWrite(ledK, LOW);
    digitalWrite(ledR, HIGH);
    Serial.println("Palang Ditutup");
    Serial.println("Palang Ditutup");
  }
}
void readRFID(){
  mfrc522.PICC_ReadCardSerial();
  //sound the buzzer when a card is read
//  oke();
  //pembatas bisa di ubah sesuai keinginan,disini yang digunakan "U"
  uidString=String(mfrc522.uid.uidByte[0], HEX)+"T"+
  String(mfrc522.uid.uidByte[1], HEX) +"I"+
  String(mfrc522.uid.uidByte[2], HEX) +"P"+
  String(mfrc522.uid.uidByte[3], HEX);
  uidString.toUpperCase();
}


void oke(){
  digitalWrite(buzzer,HIGH);
  delay(50);
  digitalWrite(buzzer,LOW);
  delay(50);
  digitalWrite(buzzer,HIGH);
  delay(50);
  digitalWrite(buzzer,LOW);
}
void gaoke(){
  digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(buzzer,LOW);
}
