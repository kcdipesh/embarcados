/*
  Rover5.h lib created by Rogério Peixoto 2013
  Released into the public domain.
*/

#include "Arduino.h"
#include "RoverDir.h"

RoverDir::RoverDir(int pin1, int pin2, int pin3, int pin4)
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);

  _pin1 = pin1;
  _pin2 = pin2;
  _pin3 = pin3;
  _pin4 = pin4;
}

void RoverDir::goFoward(){
  digitalWrite(_pin1, 1);
  digitalWrite(_pin2, 1);
  digitalWrite(_pin3, 0);
  digitalWrite(_pin4, 0);
}

void RoverDir::goBackward(){
  digitalWrite(_pin1, 0);
  digitalWrite(_pin2, 0);
  digitalWrite(_pin3, 1);
  digitalWrite(_pin4, 1);
}

void RoverDir::goRight(){
  digitalWrite(_pin1, 1);
  digitalWrite(_pin2, 0);
  digitalWrite(_pin3, 0);
  digitalWrite(_pin4, 1);
}

void RoverDir::goLeft(){
  digitalWrite(_pin1, 0);
  digitalWrite(_pin2, 1);
  digitalWrite(_pin3, 1);
  digitalWrite(_pin4, 0);
}

