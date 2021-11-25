//INISIALISASI 
int tombol1=2; //Membuat variable tombol 1 untuk pin 2 (alias)
int sensor1=3; //sama dengan atas
String kunci="dikunci";   // Variable untuk metode flag dengan nilai dikunci

int R=5;
int Y=6;
int G=7;

void setup() {
  Serial.begin(9600);
  pinMode(tombol1,INPUT);
  pinMode(sensor1,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
  digitalWrite(R,HIGH);
  Serial.println("SYSTE START!");
}

void loop() {
  //BACA SENSOR / DATA
   int bacaTombol1=digitalRead(tombol1);
   int bacaSensor1=digitalRead(sensor1);

  //PRINT KE SERIAL
   Serial.print("Tombol:");
   Serial.print(bacaTombol1);
   Serial.print("Sensor:");
   Serial.print(bacaSensor1);
   Serial.print(" | Flag:");
   Serial.print(kunci);
   Serial.println(); //UNTUK ENTER 

  //LOGIKA PROGRAM
    if (bacaTombol1==1 and kunci=="dikunci"){ 
      delay(500);
      kunci="dibuka";
      Serial.println("SELAMAT DATANG SILAHKAN AMBIL TIKET");
      Serial.println("PALANG DIBUKA");
      digitalWrite(R,LOW);
      digitalWrite(Y,HIGH);
      delay(1000);
      digitalWrite(Y,LOW);
      delay(100);
      digitalWrite(G,HIGH);
    }
    
    if (bacaSensor1==0 and kunci=="dibuka" ){ 
      delay(500);
      kunci="dikunci";
      digitalWrite(G,LOW);
      digitalWrite(R,HIGH);
      Serial.println("PALANG DITUTUP");
      delay(500);
    }  
    
}
