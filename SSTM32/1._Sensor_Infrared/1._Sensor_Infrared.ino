//INISIALISASI

//LED
const int pinM=PB1;
const int pinK=PB0;

//LDR
const int pinLDR=PA7;

//Infrared
const int pinIR=PA6;
int flagled=0;

void setup() {
  Serial.begin(9600);
  // LED
  pinMode(pinM, OUTPUT);
  pinMode(pinK, OUTPUT);
  digitalWrite(pinM, 0);
  digitalWrite(pinK, 0);

  //IR
  pinMode(pinIR, INPUT);

  //LDR
  pinMode(pinLDR, INPUT);

}

void loop() {
  // Baca Sensor
  int bacaIR=digitalRead(pinIR);
  int bacaLDR=analogRead(pinLDR);
  bacaLDR=map(bacaLDR, 20, 4095, 0, 255);

  //Print Serial
  Serial.print("Nilai IR : " + String(bacaIR));
  Serial.println(" | Nilai LDR : " + String(bacaLDR));

//  Logika

//  LDR
    if ( bacaIR == 0 ) {
      if(flagled==0){
        flagled=1;
        digitalWrite(pinK, HIGH);
      } else {
        flagled=0;
        digitalWrite(pinK, LOW);
      }
      delay(300);
    }

    // LDR
    analogWrite(pinM, bacaLDR);
    delay(100);
}
