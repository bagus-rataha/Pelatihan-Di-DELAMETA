//Inisialisasi
int pinLDR=A0;
int pinLED=6;
void setup() {
 Serial.begin(9600);
 pinMode(pinLED, OUTPUT);
}

void loop() {
//Baca Sensor/DAta
  int bacaLDR = analogRead(pinLDR);
//  bacaLDR=map(bacaLDR, 8 , 1023, 0, 255);

//Print Serial
  Serial.println("NILAI LDR :" + String(bacaLDR));

//Logika Program
  analogWrite(pinLED, bacaLDR);
  delay(50);
}
