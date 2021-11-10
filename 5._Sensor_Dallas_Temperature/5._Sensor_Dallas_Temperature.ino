//Download dan masukan Library Onewire dan DalasTemperature
#include <OneWire.h>
#include <DallasTemperature.h>

//Inisialisasi
int pintem = 2;
OneWire oneWire(pintem);
DallasTemperature sensors(&oneWire);
int pinbuz =3;

void setup() {
 Serial.begin(9600);
 sensors.begin();
 pinMode(pinbuz, OUTPUT);
 digitalWrite(pinbuz, LOW);
}

void loop() {
//Baca Sensor/DAta
  sensors.requestTemperatures();
  float bacaSuhu=sensors.getTempCByIndex(0);

//Print Serial
  Serial.println("Baca Suhu : " + String(bacaSuhu) + " C");

//Logika Program
  if (bacaSuhu > 31 ){
    digitalWrite(pinbuz, HIGH);
    delay(30);
    digitalWrite(pinbuz, LOW);
  }
}
