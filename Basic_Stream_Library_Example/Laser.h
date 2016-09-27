/*
  This is an example of how to write a library that allows user to pass in a Serial port

  Nathan Seidle
  SparkFun Electronics

  License: Public domain
*/

#include "Arduino.h" //Needed for Stream

class Laser
{
  public:
    Laser(void);

    bool begin(Stream &serialPort = Serial); //If user doesn't specificy then Serial will be used
    
    void sendCommand(String command);

  private:
    Stream *_laserSerial; //The generic connection to user's chosen serial hardware
};
