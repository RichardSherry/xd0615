void setup(){
	pinMode(2,OUTPUT);
	pinMode(3,OUTPUT);
	pinMode(4,OUTPUT);
	pinMode(5,OUTPUT);
	pinMode(6,OUTPUT);
	pinMode(7,OUTPUT);
	pinMode(8,OUTPUT);
	pinMode(9,OUTPUT);
	pinMode(10,OUTPUT);
	pinMode(11,OUTPUT);

	digitalWrite(6,HIGH);
	digitalWrite(7,HIGH);

	digitalWrite(8,HIGH);
	digitalWrite(9,HIGH);
	digitalWrite(10,HIGH);
	digitalWrite(11,HIGH);
	Serial.begin(9600);
}
byte in=0,i=8;
void loop(){
	if(Serial.available()>0){
	digitalWrite(i,LOW);
	in=Serial.read();
	in=in-'0';
	digitalWrite(2,in&0x1);
	digitalWrite(3,(in>>1)&0x1);
	digitalWrite(4,(in>>2)&0x1);
	digitalWrite(5,(in>>3)&0x1);
	digitalWrite(i,HIGH);
	delay(1000);
	i++;
	}
	else{
		in=0;
		i=8;
	}
}