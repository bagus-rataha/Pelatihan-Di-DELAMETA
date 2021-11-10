//#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <DHT.h>
#include <SerialMP3Player.h>

// DEKLARASI Cayenne Cloud
char ssid[] = "7iot";
char wifiPassword[] = "smkbisaa";
char username[] = "a1cd3940-52cf-11e9-9622-9b9aeccba453";
char password[] = "7efe594616bc3de627b21e904a9c0c404ad22499";
char clientID[] = "d84fa990-81f9-11e9-ace6-4345fcc6b81e";

//  DEKLARASI RFID
#define right_lamp 10
#define RST_PIN         D3        
#define SS_PIN          D8
#define VIRTUAL_RFID1 1
#define VIRTUAL_RFID2 2

MFRC522 mfrc522(SS_PIN, RST_PIN);

String read_rfid;
String ok_rfid_1 = "d9b89455";
String ok_rfid_2 = "97c7251b";
//String ok_rfid_2="ffffffff"; //Tambahkan sesuai kebutuhan

//  DEKLARASI Suhu dan Kelembaban Rumah
#define dht_pin D1
#define VIRTUAL_TEMP 3
#define VIRTUAL_HUM 4
DHT dht(dht_pin , DHT11);
float temp;
float hum;

//  DEKLARASI PIR
#define pir_pin D0
#define VIRTUAL_PIR 5
int pir_val;

//  DEKLARASI Servo
#define servolock_pin D4
#define servodoor_pin D2
#define VIRTUAL_SERVO 0
Servo servolock;
Servo servodoor;

//  DEKLARASI Modul MP3
#define TX 1
#define RX 3
SerialMP3Player mp3(RX,TX);


//==================================================================================================================


void setup() {
  //  Set Baudrate
  Serial.begin(9600);
  mp3.begin(9600);        // Mulai komunikasi dengan Modul MP3
  dht.begin();
  delay(500); 
  while (!Serial);
  SPI.begin();
  mfrc522.PCD_Init();
 Cayenne.begin(username, password, clientID, ssid, wifiPassword);

  //  Set Motor Servo
  servolock.attach(servolock_pin);
  servolock.write(0);
  servodoor.attach(servodoor_pin);
  servodoor.write(0);

  //  Set Lampu RFID
  digitalWrite(right_lamp, LOW);
  pinMode(right_lamp, OUTPUT);

  //  Set Sensor PIR
  pinMode(pir_pin, INPUT);
}


//==================================================================================================================


// Fungsi pembantu RFID pemecah String
  void dump_byte_array(byte *buffer, byte bufferSize) {
    read_rfid = "";
    for (byte i = 0; i < bufferSize; i++) {
      read_rfid = read_rfid + String(buffer[i], HEX);
  }
}


//==================================================================================================================


void loop() {
  Cayenne.loop();

  
   //===============================DHT 11===============================

   temp = dht.readTemperature();
   hum = dht.readHumidity();

    Cayenne.virtualWrite(VIRTUAL_TEMP, temp, TYPE_TEMPERATURE, UNIT_CELSIUS);
    Cayenne.virtualWrite(VIRTUAL_HUM, hum, TYPE_RELATIVE_HUMIDITY,UNIT_PERCENT);
    
  //=====================================================================

  //===============================PIR=================================
    
    pir_val = digitalRead(pir_pin);
    if (pir_val == HIGH) {
    Serial.println("no");
    Cayenne.virtualWrite(VIRTUAL_PIR,"1");
    mp3.playF(01);
    delay(5000);
    Cayenne.virtualWrite(VIRTUAL_PIR,"0");
    mp3.stop();
  } else {
    Serial.println("no");
    Cayenne.virtualWrite(VIRTUAL_PIR,"0");
  }
  //=====================================================================
  
  //==================================RFID===============================
    
    if ( ! mfrc522.PICC_IsNewCardPresent())
      return;

     if ( ! mfrc522.PICC_ReadCardSerial())
      return;

      dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);

    if (read_rfid == ok_rfid_1) {
     Cayenne.virtualWrite(VIRTUAL_RFID1, "1");
     digitalWrite(right_lamp, HIGH);
     delay(50);
     digitalWrite(right_lamp, LOW);
     delay(50);
     digitalWrite(right_lamp, HIGH);
     delay(50);
     digitalWrite(right_lamp, LOW);
     delay(50);
     servolock.write(90);
     delay(250);  
     servodoor.write(40);
     mp3.playF(02);
     delay(1450);
     mp3.stop();
     delay(3050);
     servodoor.write(0);
     delay(250);  
     servolock.write(0);
     Cayenne.virtualWrite(VIRTUAL_RFID1, "0");   
  }else if (read_rfid == ok_rfid_2) {
     Cayenne.virtualWrite(VIRTUAL_RFID2, "1");
     digitalWrite(right_lamp, HIGH);
     delay(50);
     digitalWrite(right_lamp, LOW);
     delay(50);
     digitalWrite(right_lamp, HIGH);
     delay(50);
     digitalWrite(right_lamp, LOW);
     delay(50);
     servolock.write(90);
     delay(250);
     servodoor.write(40);
     mp3.playF(03);
     delay(1000);
     mp3.stop();
     delay(3600);
     servodoor.write(0);
     delay(250);     
     servolock.write(0);
     Cayenne.virtualWrite(VIRTUAL_RFID2, "0");   
  }else {
     Cayenne.virtualWrite(VIRTUAL_RFID1, "0");
     Cayenne.virtualWrite(VIRTUAL_RFID2, "0");
     servolock.write(0);
     delay(250);  
     servodoor.write(0);
     digitalWrite(right_lamp, HIGH);
     delay(500);
     digitalWrite(right_lamp, LOW);
     delay(500);
     digitalWrite(right_lamp, HIGH);
     delay(500);
     digitalWrite(right_lamp, LOW);
     delay(500);
     digitalWrite(right_lamp, HIGH);
     delay(500);
     digitalWrite(right_lamp, LOW);
     mp3.playF(04);
     delay(5000);
     mp3.stop();
    }
  //==================================RFID===============================

  delay(800);
  
}


//==================================================================================================================


//Untuk Buka Pintu Manual/Darurat
CAYENNE_IN(0){
  int x = !getValue.asInt();
  if ( x == 0 ) {
    servolock.write(0);
  } else{
    servolock.write(90);
    delay(250);
    servodoor.write(90);
    delay(5000);
    servodoor.write(0);
    delay(250);
    servolock.write(0);
    }
  }
