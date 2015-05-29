#ifndef _M24AA01_H
#define _M24AA01_H
#include <Arduino.h>

/**
 * i2c serial EEPROM chip by Microchip 24AA01/24LC01B 128Byte
 * by i2c controller 
 * 
 * with the help of http://www.gammon.com.au/i2c
*/
/////////////////////////////////
// панель
class M24AA01
{
  byte m_addr;	/// address configurated by pins
public:
  M24AA01(byte addr = 0);
  /**
  * read data from EEPROM in block mode
  * 
  * @return 0 0:success
	1:data too long to fit in transmit buffer
	2:received NACK on transmit of address
	3:received NACK on transmit of data
	4:other error
	0x80: len is too big
  */
  byte read(byte address, byte *data, byte len);
  /**
  * write data to EEPROM in block mode
  * 
  * @return 0 0:success
	1:data too long to fit in transmit buffer
	2:received NACK on transmit of address
	3:received NACK on transmit of data
	4:other error
  */
  byte write(byte address, byte *data, byte len);
  
};

#endif


