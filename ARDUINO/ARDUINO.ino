
//#define CAYENNE_DEBUG       // Uncomment to show debug messages
#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space
#include <CayenneMQTTESP8266Shield.h>


//  DEKLARASICayenne Cloud
char ssid[] = "7iot";
char wifiPassword[] = "smkbisaa";
char username[] = "a1cd3940-52cf-11e9-9622-9b9aeccba453";
char password[] = "7efe594616bc3de627b21e904a9c0c404ad22499";
char clientID[] = "3a8f3d40-74d6-11e9-9636-f9904f7b864b";
#define EspSerial Serial
ESP8266 wifi(&EspSerial);

//  DEKLARASI PIR variabel SWITCH ON/OFF
#define Switch_PIR 2
#define VIRTUAL_PIRS 2

//  DEKLARASI variabel SENSOR KELEMBABAN TANAH
int sensor_val;
#define sensor_pin A2
#define water_pump 6
#define VIRTUAL_HUMIDTY 3

//  DEKLARASI variabel MQ2 Sensor
int mq2_val;
#define mq2_pin A1
#define VIRTUAL_MQ 4

//  DEKLARASI variabel SENSOR API
int flame_val;
#define flame_pin 3
#define buzzer 4
#define VIRTUAL_FLAME 5

//  DEKLARASI variabel ldr sensor
int ldr_val;
#define ldr_pin 5
#define VIRTUAL_LDR 6

//DEKLARASI variable LAMPU
#define L_TAMU 7
#define L_DAPUR 8
#define L_K1 9
#define L_K2 10
#define L_TERAS 11
#define VIRTUAL_LTAMU 7
#define VIRTUAL_LDAPUR 8
#define VIRTUAL_LK1 9
#define VIRTUAL_LK2 10
#define VIRTUAL_LTERAS 11


//==================================================================================================================


void setup(){
  Serial.begin(9600);

  // Set ESP8266 baud rate
  EspSerial.begin(9600);
  delay(10);

  Cayenne.begin(username, password, clientID, wifi, ssid, wifiPassword);
  
//  Tombol PIR
  pinMode(Switch_PIR, OUTPUT);
  digitalWrite(Switch_PIR, LOW);

//  Set Tombol LED 13
  pinMode(13,OUTPUT);
  digitalWrite(13, LOW);

//  Set Sensor Kelembaban Tanah
  pinMode(sensor_pin, INPUT);
  pinMode(water_pump, OUTPUT);
  digitalWrite(water_pump, LOW);

 // Set Sensor Api
  pinMode(flame_pin, INPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);

//  Set Sensor GAS
  pinMode(mq2_pin, INPUT);

//  Set Sensor LDR
  pinMode(ldr_pin, INPUT);

//Set Lampu
  pinMode(L_TAMU, OUTPUT);
  pinMode(L_DAPUR, OUTPUT);
  pinMode(L_K1, OUTPUT);
  pinMode(L_K2, OUTPUT);
  pinMode(L_TERAS, OUTPUT);
  digitalWrite(L_TAMU, LOW);
  digitalWrite(L_DAPUR, LOW);
  digitalWrite(L_K1, LOW);
  digitalWrite(L_K2, LOW);
  digitalWrite(L_TERAS, LOW);
  
}


//==================================================================================================================


void loop(){
  
  Cayenne.loop();

  //====================Sensor Api====================
  
  flame_val = digitalRead(flame_pin);
  if ( flame_val == LOW ){
    Cayenne.virtualWrite(VIRTUAL_FLAME, "1");
  digitalWrite(buzzer,HIGH);    
  } else {
    Cayenne.virtualWrite(VIRTUAL_FLAME, "0");
    digitalWrite(buzzer,LOW);
  }
  //===================================================  

  //==============Sensor Kelembaban Tanah==============
  
  sensor_val = analogRead(sensor_pin);
  if ( sensor_val <= 400 ){
    Cayenne.virtualWrite(VIRTUAL_HUMIDTY, sensor_val);
    digitalWrite(water_pump, LOW);
  } else {
    Cayenne.virtualWrite(VIRTUAL_HUMIDTY, sensor_val);
    digitalWrite(water_pump, HIGH);
  }
  //===================================================

  //========================MQ-2========================
  
  mq2_val = analogRead(mq2_pin);

  if ( mq2_val > 300 ){
    Cayenne.virtualWrite(VIRTUAL_MQ, "1");
    digitalWrite(buzzer, HIGH);
  } else {
    Cayenne.virtualWrite(VIRTUAL_MQ, "0");
    digitalWrite(buzzer, LOW);
  }
  //===================================================

  //========================LDR========================
  // - NIGHT == HIGH
  // - MORNING == LOW
  
  ldr_val = digitalRead(ldr_pin);
  if ( ldr_val == LOW ){
    Cayenne.virtualWrite(VIRTUAL_LDR, "1");
    digitalWrite(L_TERAS, LOW);
  } else {
    Cayenne.virtualWrite(VIRTUAL_LDR, "0");
    digitalWrite(L_TERAS, HIGH);
  }
  //===================================================

  
}


//==================================================================================================================



CAYENNE_IN (VIRTUAL_LTAMU){
  digitalWrite(L_TAMU,getValue.asInt());
      
  }

CAYENNE_IN (VIRTUAL_LDAPUR){
  digitalWrite(L_DAPUR,getValue.asInt());
  }

CAYENNE_IN (VIRTUAL_LK1){
  digitalWrite(L_K1,getValue.asInt());
  }

CAYENNE_IN (VIRTUAL_LK2){
  digitalWrite(L_K2,getValue.asInt());
  }

CAYENNE_IN (VIRTUAL_PIRS){
  digitalWrite(Switch_PIR,getValue.asInt());
      
  }
