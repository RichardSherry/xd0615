#include <MsTimer2.h> 
void setup(){
  for(int i=3;i<10;i++)
    pinMode(i,OUTPUT);
  
  pinMode(2,INPUT);
  attachInterrupt(digitalPinToInterrupt(2),onChange,CHANGE);
  
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  
  MsTimer2::set(1000,printDigital);
  MsTimer2::start();
}

void loop(){
  
}

int i=0;
void printDigital(){
  if(i==10)
    i=0;
  i=i-'0';
  digitalWrite(9,LOW);  
  digitalWrite(3,i&1);
  digitalWrite(4,(i>>1)&1);
  digitalWrite(5,(i>>2)&1);
  digitalWrite(6,(i>>3)&1);
  digitalWrite(9,HIGH);
  i=i+'0';
  i++;
}

void onChange()
{
  i=0;
}