/*
  RoverPower.h lib created by Rogério Peixoto 2013
  Released into the public domain.
*/

#ifndef RoverDir_h
#define RoverDir_h

#include "Arduino.h"

class RoverDir
{
  public:
    RoverDir(int pin1, int pin2, int pin3, int pin4);
    void goFoward();
    void goBackward();
    void goRight();
    void goLeft();
  private:
    int _pin1;
    int _pin2;
    int _pin3;
    int _pin4;
};

#endif

