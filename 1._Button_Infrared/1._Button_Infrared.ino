int bacatombol1=0;
int bacatombol2=0;

const int tombol1=2;
const int tombol2=3;

void setup() {
Serial.begin(9600);
pinMode(5,OUTPUT);
pinMode(tombol1,INPUT);
pinMode(tombol2,INPUT);
digitalWrite(5, LOW);
}


void loop() {
bacatombol1 = digitalRead(tombol1);
bacatombol2 = digitalRead(tombol2);

Serial.println("Tombol:" + String(bacatombol1) + "|" + "Sensor Val:" + String(bacatombol2));

  if(bacatombol2 != 1){
  digitalWrite(5,HIGH);
  } else{
  digitalWrite(5,LOW);
  }
}
