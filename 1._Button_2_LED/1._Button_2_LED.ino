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
    digitalWrite(6, LOW);
  } else {
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
  }
}
