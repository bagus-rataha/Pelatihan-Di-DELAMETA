//Inisialisasi
int ledM= PB10;
int ledK= PB1;
int ledH= PB0;

const int tombolM= PB13;
const int tombolK= PB14;
const int tombolH= PB15;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledM, OUTPUT);
  pinMode(ledK, OUTPUT);
  pinMode(ledH, OUTPUT);
  digitalWrite(ledM, LOW);
  digitalWrite(ledK, LOW);
  digitalWrite(ledH, LOW);
  pinMode(tombolM, INPUT);
  pinMode(tombolK, INPUT);
  pinMode(tombolH, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//  Baca Tombol
  int bacaTombolM=digitalRead(tombolM);
  int bacaTombolK=digitalRead(tombolK);
  int bacaTombolH=digitalRead(tombolH);

// SerialPrint
  Serial.println("Tombol M :" + String(bacaTombolM) + " | Tombol K :" + String(bacaTombolK) + " | Tombol H :" + String(bacaTombolH));

// Logika
  if ( bacaTombolM != 1 ) {
    digitalWrite(ledM, LOW);
  } else {
    digitalWrite(ledM, HIGH);
  }
  
  if ( bacaTombolK != 1 ) {
    digitalWrite(ledK, LOW);
  } else {
    digitalWrite(ledK, HIGH);
  }

  if ( bacaTombolH != 1 ) {
    digitalWrite(ledH, LOW);
  } else {
    digitalWrite(ledH, HIGH);
  }
}
