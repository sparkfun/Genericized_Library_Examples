Passing a Port Inside An Arduino Library
========================

These are super basic examples of how to pass an I2C port or serial port to a library. 

Why do I care?

Many libraries have Wire.write() and Serial.print() hard coded into them. More and more platforms like the SAMD21 Mini (3 Serial, 2 I2C ports) and [Teensy 3.6](https://www.kickstarter.com/projects/paulstoffregen/teensy-35-and-36/description) (6 serial, 4 I2C ports!) have multiple ports. Your library should not assume that the user will always be using Serial port 0 or the default I2C port. Instead, genericize your library so that we can do fun things like:

    myFlameThrower.begin(&Serial2);
    myHTU21D.begin(&thirdI2C);



