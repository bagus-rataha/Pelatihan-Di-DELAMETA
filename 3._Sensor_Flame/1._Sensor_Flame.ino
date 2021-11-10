//Inisialisasi
int pinFLAME=A1;
int pinLED=6;
void setup() {
 Serial.begin(9600);
 pinMode(pinLED, OUTPUT);
}

void loop() {
//Baca Sensor/DAta
  int bacaFlame = analogRead(pinFLAME);
  bacaFlame=map(bacaFlame, 20, 1021, 100, 0);

//Print Serial
  Serial.println("NILAI FLAME :" + String(bacaFlame));

//Logika Program
//  analogWrite(pinLED, bacaFlame);
//  delay(50);
}
