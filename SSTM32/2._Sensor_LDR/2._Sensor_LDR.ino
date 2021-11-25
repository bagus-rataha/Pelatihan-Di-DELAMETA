//INISIALISASI

//LED
const int pinM=PB1;


//LDR
const int pinLDR=PA7;

void setup() {
  Serial.begin(9600);
  // LED
  pinMode(pinM, OUTPUT);
  digitalWrite(pinM, 0);

  //LDR
  pinMode(pinLDR, INPUT);

}

void loop() {
  // Baca Sensor
  int bacaLDR=analogRead(pinLDR);
  bacaLDR=map(bacaLDR, 20, 4095, 0, 255);

  //Print Serial
  Serial.println("Nilai LDR : " + String(bacaLDR));

//  Logika
  analogWrite(pinM, bacaLDR);
  delay(100);
}
