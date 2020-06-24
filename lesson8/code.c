/* Blink without Delay

 Turns on and off a light emitting diode (LED) connected to a digital
 pin, without using the delay() function.  This means that other code
 can run at the same time without being interrupted by the LED code.
 在不使用delay()函数的前提下，打开/关闭一个与数字引脚连接的LED灯。这意味着其它的代码
 可以在不被LED代码打断的情况下同时运行。

 The circuit:
 * LED attached from pin 13 to ground.
 * Note: on most Arduinos, there is already an LED on the board
 that's attached to pin 13, so no hardware is needed for this example.
 电路：
 * LED从13引脚接地
 * 在大多数arduino板上已经存在一个与引脚13相连接的LED，所以在这个例子中并不需要额外硬件
 
 created 2005                           //创建于2005年
 by David A. Mellis                     //作者：David A. Mellis
 modified 8 Feb 2010                    //修订于2010年2月8日
 by Paul Stoffregen                     //作者：Paul Stoffregen
 modified 11 Nov 2013                   //修订于2013年11月11日
 by Scott Fitzgerald                    //作者：Scott Fitzgerald


 This example code is in the public domain.//此样例代码属于公众领域

 http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
 */

// constants won't change. Used here to set a pin number :
//常数不会变，在这里使用它来设置一个引脚数字
const int ledPin =  13;      // the number of the LED pin     //LED灯的引脚数字

// Variables will change :
//变量会改变
int ledState = LOW;             // ledState used to set the LED  //ledState变量用于点亮LED灯

// Generally, you should use "unsigned long" for variables that hold time//通常来说，你应该使用无符号长整型的变量用于记录时间
// The value will quickly become too large for an int to store//（时间的值）将会在短时间内变得很快从而变得不适于用int来存储
unsigned long previousMillis = 0;        // will store last time LED was updated//将记录LED等上次更新的时间

// constants won't change :
const long interval = 1000;           // interval at which to blink (milliseconds)//闪烁的时间间隔

void setup() {
  // set the digital pin as output://设置数字引脚（13）作为输出
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.
  //这里是你放置用于持续运行代码的地方

  // check to see if it's time to blink the LED; that is, if the
  // difference between the current time and last time you blinked
  // the LED is bigger than the interval at which you want to
  // blink the LED.
  /* 查看是否是LED闪烁的时候，意即：当这次闪烁和上次闪烁之间的时长大于你想要的闪烁时
  */
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    //保存上次闪烁LED的的时间
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa://如果等灭了就点亮，反之亦然
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}