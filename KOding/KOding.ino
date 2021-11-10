//Tombol
const int bagus_tombolM = PB13;
const int bagus_tombolK = PB14;
const int bagus_tombolH = PB15;

//LED
const int bagus_ledM = PB10;
const int bagus_ledK = PB1;
const int bagus_ledH = PB0;


void setup() {

  Serial.begin(9600);
  // Tombol
  pinMode(bagus_tombolM, INPUT);
  pinMode(bagus_tombolK, INPUT);
  pinMode(bagus_tombolH, INPUT);

  // LED
  pinMode(bagus_ledM, OUTPUT);
  pinMode(bagus_ledK, OUTPUT);
  pinMode(bagus_ledH, OUTPUT);
  digitalWrite(bagus_ledM, LOW);
  digitalWrite(bagus_ledK, LOW);
  digitalWrite(bagus_ledH, LOW);
}

void loop() {
  // Baca Tombol
  int bagus_bacatombolM = digitalRead(bagus_tombolM);
  int bagus_bacatombolK = digitalRead(bagus_tombolK);
  int bagus_bacatombolH = digitalRead(bagus_tombolH);

  // Print Serial
  Serial.print("Tombol M : " + String(bagus_bacatombolM));
  Serial.print(" | Tombol K : " + String(bagus_bacatombolK));
  Serial.print(" | Tombol H : " + String(bagus_bacatombolH));
  Serial.println();

  // Logika
  if ( bagus_bacatombolM == 0 ){
    digitalWrite(bagus_ledM, LOW);
  } else {
    digitalWrite(bagus_ledM, HIGH);
  }

  if ( bagus_bacatombolK == 0 ){
    digitalWrite(bagus_ledK, LOW);
  } else {
    digitalWrite(bagus_ledK, HIGH);
  }

  if ( bagus_bacatombolH == 0 ){
    digitalWrite(bagus_ledH, LOW);
  } else {
    digitalWrite(bagus_ledH, HIGH);
  }
}
