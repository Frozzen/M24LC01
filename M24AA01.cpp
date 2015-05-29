#include <Wire.h>
#include <M24AA01.h>

#define EEPROM_ADDR B1010000  // 24AA01. 7 старших битов адреса


byte M24AA01::write(byte address, byte *data, byte len)
{  
  byte r = 0;
  for(byte i=0; i<len; )
  {
    Wire.beginTransmission(EEPROM_ADDR | m_addr);
    Wire.write(address + i); 
    byte l = len > 8 ? 8 : l;
    Wire.write(data+i, l);
    r |= Wire.endTransmission();
    delay(3);
    i += l;
  }
  return r;
}

byte M24AA01::read(byte address, byte *data, byte len)
{
  Wire.beginTransmission(EEPROM_ADDR | m_addr);
  Wire.write(address);
  byte tr = Wire.endTransmission();
  if(tr)
    return tr;
  
  Wire.requestFrom((uint8_t)(EEPROM_ADDR | m_addr), len);
  byte avail = Wire.available();
  if(avail < len)
    return 0x80;
  
  for(int i=0; i < len; i++)
  {
    // store data in raw bcd format
    data[i] = Wire.read();
  }
  return 0;
}


M24AA01::M24AA01(byte addr)
{
  Wire.begin();
  m_addr = (addr & 0x7);
}