#pragma once
#include "PID.h"


PID::PID(float _Kp, float _Ki, float _Kd){
  float trash = Kp;
  Kp = _Kp;
  Ki = _Ki;
  Kd = _Kd;
  preTime = micros();
}

float PID::pid(const double goal,  double presentValue)
{
	double dt = (micros() - preTime) / 1000000;
	preTime = micros();

	P = goal - presentValue;
	I += P * dt;
	D = (P - preP) / dt;

  preP = P;
  
	return Kp*P + Ki*I + Kd*D ;
  //_Kp*P + _Ki*I + _Kd*D
}

void PID::resetI()
{
  I=0;
}
