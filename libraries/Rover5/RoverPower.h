/*
  RoverPower.h lib created by Rogério Peixoto 2013
  Released into the public domain.
*/

#ifndef RoverPower_h
#define RoverPower_h

#include "Arduino.h"

class RoverPower
{
  public:
    RoverPower(int channel1, int channel2, int channel3, int channel4);
    void throttle(int power);
    void throttleLeft(int power);
    void throttleRight(int power);
    void halt();

  private:
    int convertPowerToPWM(int power);
    int _channel1;
    int _channel2;
    int _channel3;
    int _channel4;
};

#endif

