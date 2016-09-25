/*
  This is an example of how to write a library that allows user to pass in an I2C port

  Nathan Seidle
  SparkFun Electronics

  License: Public domain
*/

#include "Memory.h"

Memory::Memory()
{
  // Constructor
}

//Initialize the I2C port
bool Memory::begin(TwoWire *wirePort)
{
  _i2cPort = wirePort; //Grab which port the user wants us to use
  
  _i2cPort->begin();
}

//Store a piece of data (thing) into a given address (place)
void Memory::writeValue(uint16_t place, uint8_t thing)
{
  _i2cPort->beginTransmission((uint8_t)EEPROM_ADDRESS);
  _i2cPort->write(place >> 8);
  _i2cPort->write(place & 0xFF);
  _i2cPort->write(thing);
  _i2cPort->endTransmission();
}

uint8_t Memory::readValue(uint16_t place)
{
  _i2cPort->beginTransmission((uint8_t)EEPROM_ADDRESS);
  _i2cPort->write(place >> 8);
  _i2cPort->write(place & 0xFF);
  _i2cPort->endTransmission();
  _i2cPort->requestFrom(EEPROM_ADDRESS, 1);   // Request 1 byte
  return ( _i2cPort->read() );
}


