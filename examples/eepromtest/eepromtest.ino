#include <Wire.h>
/**
 * Testing read/write to EEPROM
 *
 * http://www.gammon.com.au/i2c
 */



#include <M24AA01.h>
#define LEN 10

void setup()
{
  Serial.begin(9600);
  // Leonardo: wait for serial port to connect
  while (!Serial)
    {
    }
  Serial.println ();
  Serial.println ("I2C L24AA01 EEPROM test @ 0x50 ...");

  M24AA01 dev(0);
  byte buf[LEN];
  for(byte i =0; i < LEN; ++i)
    buf[i] = i;
  byte r = dev.write(0, buf, LEN);
  Serial.print("written:");
  Serial.println(r, HEX);
  memset(buf, 0, LEN);
  r = dev.read(0, buf, LEN);
  Serial.print("read:");
  Serial.println(r, HEX);
  for(byte i =0; i < LEN; ++i) {
    Serial.print(" 0x");
    Serial.print(buf[i], HEX);
  }
  
     
}

void loop()
{
  delay(1000);
}



