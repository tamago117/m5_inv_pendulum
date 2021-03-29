#pragma once
//This Library enable you to use twoWheel inversekinematics,self localization and so on. 


#include <arduino.h>
#include <stdint.h>

class twoWheel
{
public:
  //distance: distance between two tires
	twoWheel(const float distance);
  //v:velocity,w:angular velocity
	void steering(double& vR,double vL, const double v, const double w);

private:
  float d;
  double vR;
  double vL;
};

twoWheel::twoWheel(const float distance)
{
  d = distance;
}

void twoWheel::steering(double& vR,double vL, const double v, const double w)
{
	vR = v + d*w;
  vL = v - d*w;
}

