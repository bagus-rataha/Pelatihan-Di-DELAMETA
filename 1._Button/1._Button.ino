void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    for ( float i=5; i<=7; i++){
    pinMode(i, OUTPUT);
  }
    for ( float i=2; i<=4; i++){
    pinMode(i, INPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int bacaTombol=digitalRead(2);
  Serial.println("Kondisi Tombol 1 :" + String(bacaTombol));

  if ( bacaTombol != 1 ) {
    digitalWrite(5, LOW);
  } else {
    digitalWrite(5, HIGH);
  }

  int bacaTombol1=digitalRead(3);
  Serial.println("Kondisi Tombol 2 :" + String(bacaTombol1));

  if ( bacaTombol1 != 1 ) {
    digitalWrite(6, LOW);
  } else {
    digitalWrite(6, HIGH);
  }

  int bacaTombol2=digitalRead(4);
  Serial.println("Kondisi Tombol 3 :" + String(bacaTombol2));

  if ( bacaTombol2 != 1 ) {
    digitalWrite(7, LOW);
  } else {
    digitalWrite(7, HIGH);
  }
}
