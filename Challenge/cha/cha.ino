//Inisialisasi
int pinFLAME=A1;
int pinR=6;
int pinbuz = 5;
int pinLDR = A0;
int pinK = 7;
int pinH = 8;
void setup() {
 Serial.begin(9600);
 pinMode(pinR, OUTPUT);
 pinMode(pinK, OUTPUT);
 pinMode(pinH, OUTPUT);
 pinMode(pinbuz, OUTPUT);
 digitalWrite(pinbuz, LOW);
 digitalWrite(pinR, LOW);
 digitalWrite(pinK, LOW);
 digitalWrite(pinH, LOW);
}

void loop() {
//Baca Sensor/DAta

//Flame
  int bacaFlame = analogRead(pinFLAME);
  bacaFlame=map(bacaFlame, 20, 1021, 100, 0);

//  LDR
  int bacaLDR = analogRead(pinLDR);
  bacaLDR=map(bacaLDR, 12, 1023, 0, 255);

//Print Serial
//  Serial.println("NILAI FLAME :" + String(bacaFlame));

//Logika Program

//  Flame
  if (bacaFlame < 9 ){
    Serial.println("Aman Banget");
    digitalWrite(pinbuz, LOW);
    digitalWrite(pinH, HIGH);
    digitalWrite(pinK, LOW);
  } else if ( bacaFlame >=10 and bacaFlame < 50 ){
    Serial.println("Warning Silahkan Periksa");
    digitalWrite(pinK, HIGH);
    digitalWrite(pinH, LOW);
    digitalWrite(pinbuz, HIGH);
    delay(200);
    digitalWrite(pinbuz, LOW);
  } else {
    Serial.println("Waspada harap mengungsi");
    digitalWrite(pinK, HIGH);
    digitalWrite(pinH, HIGH);
    digitalWrite(pinbuz, HIGH);
    delay(50);
    digitalWrite(pinbuz, LOW);
  }
//  LDR
    analogWrite(pinR, bacaLDR);
    delay(50);
}
