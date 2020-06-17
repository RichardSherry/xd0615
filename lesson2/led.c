int i;
void setup()
{
  for(i=0;i<8;i++){
    pinMode(i,OUTPUT);
  }
}

void loop()
{
  for(i=0;i<8;i=i+2){
    digitalWrite(i, HIGH);
    delay(500); // Wait for 1000 millisecond(s)
    digitalWrite(i, LOW);
    delay(500); // Wait for 1000 millisecond(s)
  }
  for(i=1;i<8;i=i+2){
    digitalWrite(i,HIGH);
    delay(200);
    digitalWrite(i,LOW);
    delay(500);
  }
}