//This Library enable you to use twoWheel inversekinematics,self localization and so on. 

#ifndef twoWheel_H
#define twoWheel_H

#include <arduino.h>
#include <stdint.h>

class twoWheel
{
public:
  //distance: distance between two tires
	twoWheel(uint8_t pin1, uint8_t pin2,uint8_t pin3, uint8_t pin4,float distance);
  //v:velocity,w:angular velocity
	void steering(float v,float w);

protected:
	uint8_t _pin1;
	uint8_t _pin2;
  uint8_t _pin3;
  uint8_t _pin4;

private:
  float _v;
  float _w;
  float d;
  float vR;
  float vL;
};

#endif
