//Download dan masukan Library Onewire dan DalasTemperature
#include <NewPing.h>

//Inisialisasi
int tri = 5;
int echo= 4;
int batas=200;
int pinM=6;
int pinK=7;
int pinH=8;
int pinbuz=3;

NewPing cm(tri,echo,batas);

void setup() {
 Serial.begin(9600);
 pinMode(tri, INPUT);
 pinMode(echo, INPUT);
 pinMode(pinM, OUTPUT);
 pinMode(pinK, OUTPUT);
 pinMode(pinH, OUTPUT);
 pinMode(pinbuz, OUTPUT);
 digitalWrite(pinM, LOW);
 digitalWrite(pinK, LOW);
 digitalWrite(pinH, LOW);
 digitalWrite(pinbuz, LOW);
}

void loop() {
//Baca Sensor/DAta
  int bacaJarak=cm.ping_cm();

//Print Serial
  Serial.print("Baca Jarak : " + String(bacaJarak) + " cm   |");
//Logika Program
  if ( bacaJarak == 0 ) {
    Serial.println("AMAN");
    digitalWrite(pinK, LOW);
    digitalWrite(pinM, LOW);
    digitalWrite(pinH, HIGH);
    digitalWrite(pinbuz, LOW);
  } else if ( bacaJarak < 20 ) {
    Serial.println("BERHENTI");
    digitalWrite(pinM, HIGH);
    digitalWrite(pinK, LOW);
    digitalWrite(pinH, LOW);
    digitalWrite(pinbuz, HIGH);
    delay(300);
    digitalWrite(pinbuz, LOW);
    delay(300);
  } else if ( bacaJarak >= 21 && bacaJarak <= 70 ) {
    Serial.println("BAHAYA");
    digitalWrite(pinK, HIGH);
    digitalWrite(pinM, LOW);
    digitalWrite(pinH, LOW);
    digitalWrite(pinbuz, HIGH);
    delay(800);
    digitalWrite(pinbuz, LOW);
    delay(800);
  } else {
    Serial.println("AMAN");
    digitalWrite(pinK, LOW);
    digitalWrite(pinM, LOW);
    digitalWrite(pinH, HIGH);
    digitalWrite(pinbuz, LOW);
  }
}
