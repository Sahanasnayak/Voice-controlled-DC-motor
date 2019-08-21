#include<SoftwareSerial.h>
String readmsg;
 #define enA 9
 #define enB 10
 #define in1 5
 #define in2 6
 #define in3 7
 #define in4 8
 const int txpin=1;
const int rxpin=0;
 SoftwareSerial BT(rxpin,txpin);


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
   BT.begin(9600);
  pinMode(enA, OUTPUT);
   pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
}


void loop() {
  // put your main code here, to run repeatedly:
 analogWrite(enA, 255);
 analogWrite(enB, 255);
 while(BT.available()){
  delay(10);
   char c=BT.read();
  readmsg+=c;
  }
  
  if(readmsg.length()>0){
if(readmsg=="*forward#"){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  //delay(100);
}

    else if(readmsg=="*backward#"){
   digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
   //delay(100);
   
   }
   
   else if(readmsg=="*left#"){
     
    digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
    //delay(100);
    }
    
    else if(readmsg=="*right#"){
    
   digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
    delay(100);
    }
    
     else if(readmsg=="*dance#"){
      
    
   digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
    delay(300);
    
   digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
    delay(600);
  
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  delay(300);
  
   digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
    delay(600);
  
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  delay(300);
  
 digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
    delay(600);
    
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
    delay(600);

     digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
    delay(300);

    digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
   delay(600); 
    }
    
     else if(readmsg=="*stop#"){
   digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
   // delay(100);
    }
    
    Serial.println(readmsg);
    readmsg="";
  }
}
