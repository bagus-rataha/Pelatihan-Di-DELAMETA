int ledM= PB10;
int ledK= PB1;
int ledH= PA8;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledM, OUTPUT);
  pinMode(ledK, OUTPUT);
  pinMode(ledH, OUTPUT);
  digitalWrite(ledM, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledM, HIGH);
  delay(500);
  digitalWrite(ledM, LOW);
  digitalWrite(ledK, HIGH);
  delay(500);
  digitalWrite(ledK, LOW);
  digitalWrite(ledH, HIGH);
  delay(500);
  digitalWrite(ledH, LOW);
}
