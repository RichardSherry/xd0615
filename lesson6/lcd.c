#include <LiquidCrystal.h>
String str="",str2="";
int i=0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
	lcd.begin(16, 2);
	Serial.begin(9600);
}

	void loop() {
	while (Serial.available() > 0)
	{
		if(i<16){
		str += (char)Serial.read();
		delay(10);
		i++;
		}
		else{
			str2+=(char)Serial.read();
			delay(10);
			i++;
		}
	}

	if (str.length() > 0)
	{
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print(str);
		if(i>16){
			lcd.setCursor(0,1);
			lcd.print(str2);
		}
	}
	
	delay(10);
	str = "";
	str2="";
	i=0;
}