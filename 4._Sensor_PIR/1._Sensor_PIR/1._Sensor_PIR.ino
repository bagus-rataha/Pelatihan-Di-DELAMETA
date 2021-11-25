//Inisialisasi
int pinPIR=PA3;
//int pinBUZ=5;

void setup() {
 Serial.begin(9600);
 pinMode(pinPIR, INPUT);
// pinMode(pinBUZ, OUTPUT);
// digitalWrite(pinBUZ, LOW);
}

void loop() {
//Baca Sensor/DAta
  int bacaPIR = digitalRead(pinPIR);
  
//Print Serial
  Serial.println("PIR :" + String(bacaPIR));
  delay(500);
//Logika Program
//  if ( bacaPIR != 0 ) {
//    Serial.println("Ada Maling");
//    digitalWrite(pinBUZ, HIGH);
//    delay(50);
//    digitalWrite(pinBUZ, LOW);
//    delay(50);
//    digitalWrite(pinBUZ, HIGH);
//    delay(50);
//    digitalWrite(pinBUZ, LOW);
//  } else {
//    Serial.println("Aman");
//    digitalWrite(pinBUZ, LOW);
//  }
}
