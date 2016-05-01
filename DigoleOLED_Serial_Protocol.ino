#define _Digole_Serial_I2C_

#include <DigoleSerial.h>
#include <Wire.h>
DigoleSerialDisp mydisp(&Wire,'\x27');  //I2C:Arduino UNO: SDA (data line) is on analog input pin 4, and SCL (clock line) is on analog input pin 5 on UNO and Duemilanove

#define LCDCol 16
#define LCDRow 2

void resetpos(void) //for demo use, reset display position and clean the demo line
{
    mydisp.setPrintPos(0, 1);
    delay(2000); //delay 2 seconds
    mydisp.println("                "); //display space, use to clear the demo line
    mydisp.setPrintPos(0, 1);
}

void setup()
{
  Serial.begin(9600);
  mydisp.begin();
  mydisp.clearScreen();
}

void loop()
{
  if(Serial.available())
  {
    int i = 0;
    mydisp.clearScreen();
    while(Serial.available())
    {
      char c = Serial.read();
      if(c == '\\')
      {
        mydisp.setPrintPos(0, ++i);
        continue;
      }
      mydisp.print(c);
    }
  }
}
/*void setup() {
    mydisp.begin();

    mydisp.disableCursor(); //disable cursor, enable cursore use: enableCursor();
    mydisp.drawStr(4, 0, "Demo now"); //display string at: x=4, y=0

    //Test print function
    mydisp.setPrintPos(0, 1);
    mydisp.print(a); // display a char array
    resetpos();
    mydisp.print("display a char:");
    mydisp.print(b); //display a char
    resetpos();
    mydisp.print("int as DEC:");
    mydisp.print(c); //display 3456 in Dec
    resetpos();
    mydisp.print("as HEX:");
    mydisp.print(c, HEX); //display 3456 in Hex
    resetpos();
    mydisp.print("as OCT:");
    mydisp.print(c, OCT); //display 3456 in Oct
    resetpos();
    mydisp.print("BIN:");
    mydisp.print(c, BIN); //display 3456 in Bin
    resetpos();
    mydisp.print(d); //display String object
    resetpos();
    mydisp.print("float pi=");
    mydisp.print(pi); //display float of PI
    resetpos();
    mydisp.print("Pi6=");
    mydisp.print(pi, 6); //display PI in 6 Accuracy
    resetpos();
    mydisp.print("Pi*3=");
    mydisp.print(pi * 3, 6); //display PI time 3 in 6 Accuracy
    resetpos();
    mydisp.print("lg5=");
    mydisp.print(log(5), 8); //display log(5) in 8 Accuracy
    resetpos();
    mydisp.clearScreen();
    mydisp.enableCursor(); //enable cursor
}*/
