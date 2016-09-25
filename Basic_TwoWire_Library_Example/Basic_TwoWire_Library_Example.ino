/*
  Example of how to pass an I2C object to a library
  Nathan Seidle
  SparkFun Electronics
  September 24th, 2016

  Many libraries are written with Wire.read and Wire.write hard coded. These libs won't
  work if you want to use an I2C port other than Wire. This is an example of how to write a library
  that genericizes the I2C port.
  
  This example talks to an I2C eeprom, the 24LC256 with all ADR pins pulled to ground. 
  External EEPROM is needed if you have a micro (like the SAMD21) that doesn't have EEPROM built-in. 
  I needed this for waypoint storage on my AVC vehicle.

  David wrote a great tutorial covering the basics of library creation so start there
  https://www.arduino.cc/en/Hacking/LibraryTutorial
*/

//This is our example library
#include "Memory.h"
Memory myStorage;

//Uncomment the following block for testing on SAMD21
//#include <Wire.h>
//TwoWire secondI2C(&sercom1, 11, 13); //SDA = 11, SCL = 13

//Uncomment the following block for testing with software I2C on an Uno
//#include <SoftwareWire.h>
//SoftwareWire myWire(2, 3); //SDA = 2, SCL = 3

void setup()
{
  //Uncomment the following block for testing with normal I2C port on Uno
  Serial.begin(9600); //For printing local debug messages
  myStorage.begin(); //Uno - With an empty call this will default to Wire.read, Wire.write, etc
  //myStorage.begin(&Wire); //Uno - This will use Wire.read, Wire.write, etc

  //Uncomment the following block for testing on SAMD21
  //SerialUSB.begin(9600); //For printing local debug messages
  //myStorage.begin(&secondI2C); //SAMD21 - This will use the 2nd hardware I2C port on the SAMD21 Mini

  //Uncomment the following block for testing with software I2C on an Uno
  //Serial.begin(9600); //For printing local debug messages
  //myWire.begin();
  //myStorage.begin(&myWire); //This will use the software based I2C library
}

void loop()
{
  myStorage.writeValue(12, 163); //Write value 163 into address 12

  delay(10); //Give the EEPROM time to record this value
  
  int value = myStorage.readValue(12); //Read what is in location 12

  //For Uno
  Serial.print("value (should be 163): ");
  Serial.println(value);

  //For SAMD21
  //SerialUSB.print("value: ");
  //SerialUSB.println(value);

  delay(1000);
}

