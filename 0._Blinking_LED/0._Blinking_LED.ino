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
// Bareng
//  digitalWrite(merah, HIGH);
//  digitalWrite(kuning, HIGH);
//  digitalWrite(hijau,HIGH);
//  delay(800);
//  digitalWrite(merah, LOW);
//  digitalWrite(kuning, LOW);
//  digitalWrite(hijau,LOW);
//  delay(800);

//Bergantian
  digitalWrite(merah, HIGH);
  delay(500);
  digitalWrite(merah, LOW);
  digitalWrite(kuning, HIGH);
  delay(500);
  digitalWrite(kuning, LOW);
  digitalWrite(hijau, HIGH);
  delay(500);
  digitalWrite(hijau, LOW);
}
