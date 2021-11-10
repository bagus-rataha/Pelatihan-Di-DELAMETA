//Inisialisasi
int bagus_ledM= PB10;
int bagus_ledK= PB1;
int bagus_ledH= PB0;

const int bagus_tombolM= PB13;
const int bagus_tombolK= PB14;
const int bagus_tombolH= PB15;

int flag1=0;
int flag2=0;
int flag3=0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(bagus_ledM, OUTPUT);
  pinMode(bagus_ledK, OUTPUT);
  pinMode(bagus_ledH, OUTPUT);
  digitalWrite(bagus_ledM, LOW);
  digitalWrite(bagus_ledK, LOW);
  digitalWrite(bagus_ledH, LOW);
  pinMode(bagus_tombolM, INPUT);
  pinMode(bagus_tombolK, INPUT);
  pinMode(bagus_tombolH, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//  Baca Tombol
  int readM=digitalRead(bagus_tombolM);
  int readK=digitalRead(bagus_tombolK);
  int readH=digitalRead(bagus_tombolH);

//Serial Print
  Serial.println("Tombol M : " + String(readM) + " | Tombol K : " + String(readK) + " | Tombol H : " + String(readH));

//  Logika
  if(readM==HIGH){
    if(flag1==0){
      flag1=1;
      digitalWrite(bagus_ledM, HIGH);
    } else {
      flag1=0;
      digitalWrite(bagus_ledM, LOW);
    }
  delay(300);
  } else if(readK==HIGH){
    if(flag2==0){
      flag2=1;
      digitalWrite(bagus_ledK, HIGH);
    } else {
      flag2=0;
      digitalWrite(bagus_ledK, LOW);
    }
  delay(300);
  } else if(readH==HIGH){
    if(flag3==0){
      flag3=1;
      digitalWrite(bagus_ledH, HIGH);
    } else {
      flag3=0;
      digitalWrite(bagus_ledH, LOW);
    }
  delay(300);
  }
  
  
}
