#pragma once
#include "PID.h"


PID::PID(float Kp, float Ki, float Kd){
  trash = Kp;
  _Kp = Kp;
  _Ki = Ki;
  _Kd = Kd;
}

float PID::pid(float goal,float presentValue)
{
	dt = (micros() - preTime) / 1000000;
	preTime = micros();

	P = goal - presentValue;
	I += P * dt;
	D = (P - preP) / dt;

  preP = P;
  
	return _Kp*P + _Ki*I + _Kd*D ;
  //_Kp*P + _Ki*I + _Kd*D
}

void PID::resetI()
{
  I=0;
}
