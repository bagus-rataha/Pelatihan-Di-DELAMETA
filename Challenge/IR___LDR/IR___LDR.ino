//LED
const int pinM=PB1;
const int pinK=PB0;
const int pinH=PA5;

//IR
const int pinIR=PA6;

//LDR
const int pinLDR=PA7;

int flag=1;

void setup() {

  Serial.begin(9600);
  // LED
  pinMode(pinM, OUTPUT);
  pinMode(pinK, OUTPUT);
  pinMode(pinH, OUTPUT);
  digitalWrite(pinM, LOW);
  digitalWrite(pinK, LOW);
  digitalWrite(pinH, LOW);

  pinMode(pinIR, INPUT);
  pinMode(pinLDR, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int bacaIR=digitalRead(pinIR);
  int bacaLDR=analogRead(pinLDR);
//  bacaLDR=map(bacaLDR, 20, 4095, 0, 255);

  Serial.print(flag);
  Serial.println(" | " + String(bacaLDR));

  if (bacaIR == 0 && flag == 1){
    flag--;
    delay(300);
  } else if (bacaIR == 0 && flag == 0) {
    flag++;
    delay(300);
  }
  
  if (flag == 0 ){
    if(bacaLDR < 1000 ){
      digitalWrite(pinM, HIGH);
      digitalWrite(pinK, LOW);
      digitalWrite(pinH, LOW);
    } else if ( bacaLDR > 1000 && bacaLDR < 3900){
      digitalWrite(pinK, HIGH);
      digitalWrite(pinH, LOW);
      digitalWrite(pinM, LOW);
    } else if ( bacaLDR > 4000 ){
      digitalWrite(pinH, HIGH);
      digitalWrite(pinK, LOW);
      digitalWrite(pinM, LOW);
   } 
   } else if ( flag == 1 ) {
      digitalWrite(pinM, LOW);
      digitalWrite(pinH, LOW);
      digitalWrite(pinK, LOW);
  }
  
}
