#pragma once
#include <Arduino.h>

class PID
{
public:
  PID(float _Kp, float _Ki, float _Kd);
	float update(const double goal, const double presentValue);
  void resetI();
private:
	float Kp;
	float Ki;
	float Kd;
	float goal;
	float presentValue;
  float preP=0;
  int preTime;
  double P;
  double I=0;
  double D;
 
};

