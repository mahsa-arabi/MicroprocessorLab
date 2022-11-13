#include <EEPROM.h>

int numBytes = 200;
int i = 0;
int j = 0;
String letters[40] = {"a", "b", "c", "d", "e", "f","g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};
String randString = "";

void writeStringToEEPROM(int addrOffset, const String &strToWrite)
{
  byte len = strToWrite.length();
  EEPROM.write(addrOffset, len);
  for (int i = 0; i < len; i++)
  {
    EEPROM.write(addrOffset + 1 + i, strToWrite[i]);
  }
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()) 
  {
    numBytes = Serial.parseInt();
    for(i = 0; i<numBytes; i++)
    {
     randString = randString + letters[random(0, 40)];
   
    }
    writeStringToEEPROM(0, randString);
    delay(1000);
  }
}