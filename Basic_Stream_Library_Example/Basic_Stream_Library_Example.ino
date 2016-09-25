/*
  Example of how to pass a Serial Port object to a library
  Nathan Seidle
  SparkFun Electronics
  September 24th, 2016

  Many libraries are written with Serial.print and Serial.read hard coded. These libs won't
  work if you want to use Serial1, Serial2, etc. This is an example of how to write a library
  that genericizes the Serial port.

  This example sends out print statements to a make believe laser module

  David wrote a great tutorial covering the basics of library creation so start there
  https://www.arduino.cc/en/Hacking/LibraryTutorial
*/

//This is our example library
#include "Laser.h"
Laser myLaser;

//Uncomment the following block for testing on SAMD21
//Uart laserSerial2 (&sercom1, 11, 10, SERCOM_RX_PAD_0, UART_TX_PAD_2); //RX on 11, TX on 10
//void SERCOM1_Handler()
//{
//  laserSerial2.IrqHandler();
//}

//Uncomment the following block for testing with software serial on an Uno
//#include <SoftwareSerial.h>
//SoftwareSerial mySerial(6, 5); // RX = 6, TX = 5

void setup()
{
  //Uncomment the following block for testing with normal Serial port on Uno
  Serial.begin(9600); //We have to start the serial port before we call begin()
  myLaser.begin(); //With an empty call this will default to Serial.print, Serial.read, etc
  //myLaser.begin(&Serial); //Passing &Serial does the same: this will use Serial.print, Serial.read, etc

  //Uncomment the following block for testing on SAMD21
  //SerialUSB.begin(9600); //For printing local debug messages
  //laserSerial2.begin(9600); //We have to start the serial port before we call begin()
  //myLaser.begin(&laserSerial2); //This will use the 2nd hardware serial port on the SAMD21 Mini

  //Uncomment the following block for testing with software serial on an Uno
  //Serial.begin(9600); //For printing local debug messages
  //mySerial.begin(9600); //We have to start the serial port before we call begin()
  //myLaser.begin(&mySerial); //This will use the SoftwareSerial library
}

void loop()
{
  myLaser.sendCommand("Fire the laser!"); //Send a serial command to the device

  Serial.println("Command sent"); //For Uno
  //SerialUSB.println("Command sent"); //For SAMD21

  delay(1000);
}
