// Include
#include <NewPing.h>

//Inisialisasi

//LED
const int ledM=PB10;
const int ledK=PB1;
const int ledH=PB0;

// PIR
  const int pinPIR=PA3;


//Ultra
const int tri=PA4;
const int echo=PA5;
int batas=200;
NewPing cm(tri, echo, batas);


int flag=1;

void setup()  {
  Serial.begin(9600);
//  LED
  pinMode(ledM, OUTPUT);
  pinMode(ledK, OUTPUT);
  pinMode(ledH, OUTPUT);
  digitalWrite(ledM, LOW);
  digitalWrite(ledK, LOW);
  digitalWrite(ledH, LOW);

//PIR
  pinMode(pinPIR, INPUT);

//  Ultra
  pinMode(tri, INPUT);
  pinMode(echo, INPUT);
}

void loop ()  {
//  Baca Sensor
  int bacaJarak=cm.ping_cm();
  int bacaPIR=digitalRead(pinPIR);

//  Serial
  
//  Logika
  if (bacaPIR == 1 && flag == 1) {
    flag=0;
//    delay(300);
  } if (bacaPIR == 1 && flag == 0) {
    flag++;
//    delay(300);
  }
//  Serial.print("Jarak : " + String(bacaJarak) + " cm");
  Serial.println(" | Flag : " + String(flag) + " | PIR : " + String(bacaPIR));

  delay(9000);
//  Pilihan Flag
  if(flag == 1 ){
     if (bacaJarak > 70 || bacaJarak == 0 ) {
      Serial.println(" | AMAN");
      digitalWrite(ledH, HIGH);
      delay(200);
      digitalWrite(ledH, LOW);
      digitalWrite(ledK, HIGH);
      delay(200);
      digitalWrite(ledK, LOW);
      digitalWrite(ledM, HIGH);
      delay(200);
      digitalWrite(ledM, LOW);
      digitalWrite(ledK, HIGH);
      delay(200);
      digitalWrite(ledK, LOW);
      digitalWrite(ledH, HIGH);
      delay(200);
      digitalWrite(ledH, LOW);
      delay(200);
     } else if ( bacaJarak < 20 ){
      Serial.println(" | BERHENTI");
      digitalWrite(ledK, HIGH);
      digitalWrite(ledM, HIGH);
      digitalWrite(ledH, HIGH);
      delay(100);
      digitalWrite(ledK, LOW);
      digitalWrite(ledM, LOW);
      digitalWrite(ledH, LOW);
     } else if ( bacaJarak > 20 && bacaJarak <= 70 ){
      Serial.println(" | BAHAYA");
      digitalWrite(ledK, HIGH);
      digitalWrite(ledM, HIGH);
      digitalWrite(ledH, HIGH);
      delay(800);
      digitalWrite(ledK, LOW);
      digitalWrite(ledM, LOW);
      digitalWrite(ledH, LOW);
     }
  } else if ( flag == 0 ){
     digitalWrite(ledK, LOW);
     digitalWrite(ledM, LOW);
     digitalWrite(ledH, LOW);
  }
}
