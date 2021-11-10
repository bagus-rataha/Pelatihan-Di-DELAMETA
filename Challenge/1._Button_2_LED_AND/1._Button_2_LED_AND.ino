int bacatombol1=0;
int bacatombol2=0;

const int tombol1=2;
const int tombol2=3;

void setup() {
pinMode(5,OUTPUT);
pinMode(tombol1,INPUT);
pinMode(tombol2,INPUT);
}


void loop() {
bacatombol1 = digitalRead(tombol1);
bacatombol2 = digitalRead(tombol2);

  if(bacatombol1 != 0 || bacatombol2 != 0){
  digitalWrite(5,HIGH);
  } else{
  digitalWrite(5,LOW);
  }
}
