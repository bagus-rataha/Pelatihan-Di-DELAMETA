void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  for ( float i=5; i<=7; i++){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  for (float i=0; i<=255; i++) {
    analogWrite(5, i);
//    float hasil=map(i,0,255,0,5);
    float hasil=(5.0/255.0)*i;
    Serial.println("DATA :" + String(hasil) + " Volt");
    delay(10);
  } 
  for (float i=255; i>=0; i--) {
    analogWrite(5, i);
//    float hasil=map(i,0,255,0,5);
  float hasil=(5.0/255.0)*i;
    Serial.println("DATA :" + String(hasil) + "Volt");
    delay(10);
  }
}
