#pragma once
#include "twoWheel.h"

twoWheel::twoWheel(uint8_t pin1, uint8_t pin2,uint8_t pin3, uint8_t pin4,float distance)
{
  _pin1 = pin1;
  _pin2 = pin2;
  _pin3 = pin3;
  _pin4 = pin4;
  d = distance;
}

void twoWheel::steering(float v,float w)
{
  _v = v;
  _w = w;
	vR = _v + d*_w;
  vL = _v - d*_w;

  
}
