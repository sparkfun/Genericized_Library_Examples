/*
  This is an example of how to write a library that allows user to pass in a Serial port

  Nathan Seidle
  SparkFun Electronics

  License: Public domain
*/

#include "Laser.h"

Laser::Laser(void)
{
  // Constructor
}

//Initialize the Serial port
bool Laser::begin(Stream &serialPort)
{
  _laserSerial = &serialPort; //Grab which port the user wants us to use

 //_laserSerial->begin(); //Stream has no .begin() so the user has to do a whateverSerial.begin(xxxx); from setup()
}

//Send a command to the laser
void Laser::sendCommand(String command)
{
  _laserSerial->println(command);
}



