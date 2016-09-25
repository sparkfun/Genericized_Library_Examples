/*
  This is an example of how to write a library that allows user to pass in an I2C port

  Nathan Seidle
  SparkFun Electronics

  License: Public domain
*/

#include <Wire.h>

#define EEPROM_ADDRESS 0x50 //This is the 7-bit I2C address of the 24LC256 with all ADR pins pulled to ground

class Memory
{
 public: 
  Memory(void);

  bool begin(TwoWire *wirePort = &Wire); //If user doesn't specificy then Wire will be used

  void writeValue(uint16_t place, uint8_t thing);
  uint8_t readValue(uint16_t place);

 private:
  TwoWire *_i2cPort; //The generic connection to user's chosen I2C hardware
};
