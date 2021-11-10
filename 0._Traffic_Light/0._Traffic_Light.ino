  int merah=5;
  int kuning=6;
  int hijau=7;
void setup() {
  // put your setup code here, to run once:

  pinMode(merah, OUTPUT);
  pinMode(kuning, OUTPUT);
  pinMode(hijau, OUTPUT);
}

void loop() {
//Bergantian
  digitalWrite(merah, HIGH);
  delay(2000);
  digitalWrite(merah, LOW);
  digitalWrite(kuning, HIGH);
  delay(500);
  digitalWrite(kuning, LOW);
  digitalWrite(hijau, HIGH);
  delay(2000);
  digitalWrite(hijau, LOW);
  digitalWrite(kuning, HIGH);
  delay(500);
  digitalWrite(kuning, LOW);
}
