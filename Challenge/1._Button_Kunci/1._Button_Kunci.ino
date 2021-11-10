//Definisi Led 1 Merah
const int button1 = PB13;           
const int led1 =PB10;             
int flagled1=0;

//Definisi Led 2 Kuning
const int button2 = PB14;           
const int led2 =PB1;             
int flagled2=0;

//Definisi Led 3 Hijau
const int button3 = PB15;           
const int led3 =PA8;             
int flagled3=0;             

void setup() {
//  Led 1
  pinMode(button1,INPUT);        
  pinMode(led1,OUTPUT);           
  digitalWrite(led1,LOW);

//  Led 2
  pinMode(button2,INPUT);        
  pinMode(led2,OUTPUT);           
  digitalWrite(led2,LOW);

//  Led 3
  pinMode(button3,INPUT);        
  pinMode(led3,OUTPUT);           
  digitalWrite(led3,LOW);       
}

void loop() {
  if (digitalRead(button1)==HIGH){    //Kondisi pertama untuk led 1//
    if (flagled1==0) {                //Periksa tanda flag = 0//
      flagled1=1;                     //Tandai flagnya jadi high//
      digitalWrite(led1,HIGH);        //Nyalakan lampu//
      }                           
    else {                            //Sebaliknya != 0/1 eksekusi ini//
      flagled1=0;                     //Tandai lagi flagnya jadi LOW//
      digitalWrite(led1,LOW);         //Matikan lampu//
    }
  delay(300);                    
  } else if (digitalRead(button2)==HIGH){   //Kondisi kedua untuk led 2//
    if (flagled2==0) {            
      flagled2=1;                 
      digitalWrite(led2,HIGH);     
      }                           
    else {                       
      flagled2=0;                  
      digitalWrite(led2,LOW);      
    }
  delay(300); 
  } else if (digitalRead(button3)==HIGH){     //Kondisi ketiga untuk led 3//
    if (flagled3==0) {            
      flagled3=1;                 
      digitalWrite(led3,HIGH);     
      }                           
    else {                       
      flagled3=0;                  
      digitalWrite(led3,LOW);      
    }
  delay(300);                                 //  Jeda sebentar supaya stabil loopnya ga kecepetan //
  }                        
}                                
