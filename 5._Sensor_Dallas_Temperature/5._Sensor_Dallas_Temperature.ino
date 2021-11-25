//Download dan masukan Library Onewire dan DalasTemperature
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

//Inisialisasi
int pintem = PA3;
OneWire oneWire(pintem);
DallasTemperature sensors(&oneWire);
int pinbuz =3;

void setup() {
 Serial.begin(9600);
 sensors.begin();
 pinMode(pinbuz, OUTPUT);
 digitalWrite(pinbuz, LOW);
 lcd.begin();
}

void loop() {
//Baca Sensor/DAta
  sensors.requestTemperatures();
  float bacaSuhu=sensors.getTempCByIndex(0);

//Print Serial
//  Serial.println("Baca Suhu : " + String(bacaSuhu) + " C");
//  lcd.clear();
  lcd.setCursor(0,0); lcd.print("Suhu : " + String(bacaSuhu));

//Logika Program
//  if (bacaSuhu > 31 ){
//    digitalWrite(pinbuz, HIGH);
//    delay(30);
//    digitalWrite(pinbuz, LOW);
//  }
}
