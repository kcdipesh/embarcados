/*
  RoverPower.h lib created by Rogério Peixoto 2013
  Released into the public domain.
*/

#include "Arduino.h"
#include "RoverPower.h"

RoverPower::RoverPower(int channel1, int channel2, int channel3, int channel4)
{
  pinMode(channel1, OUTPUT);
  pinMode(channel2, OUTPUT);
  pinMode(channel3, OUTPUT);
  pinMode(channel4, OUTPUT);

  _channel1 = channel1;
  _channel2 = channel2;
  _channel3 = channel3;
  _channel4 = channel4;
}

void RoverPower::throttle(int power){
  analogWrite(_channel1, convertPowerToPWM(power));
  analogWrite(_channel2, convertPowerToPWM(power));
  analogWrite(_channel3, convertPowerToPWM(power));
  analogWrite(_channel4, convertPowerToPWM(power));
}

void RoverPower::throttleLeft(int power){
  analogWrite(_channel1, convertPowerToPWM(power));
  analogWrite(_channel3, convertPowerToPWM(power));
}

void RoverPower::throttleRight(int power){
  analogWrite(_channel2, convertPowerToPWM(power));
  analogWrite(_channel4, convertPowerToPWM(power));
}

void RoverPower::halt(){
  analogWrite(_channel1, 0x00);
  analogWrite(_channel2, 0x00);
  analogWrite(_channel3, 0x00);
  analogWrite(_channel4, 0x00);
}

int RoverPower::convertPowerToPWM(int power){
  return power * 255 / 100;
}

