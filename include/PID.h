#ifndef PID_H
#define PID_H

#include <Arduino.h>

class PID
{
public:
  PID(float Kp, float Ki, float Kd);
	float pid( float goal,float presentValue);
  void resetI();
private:
  float trash;
	float _Kp;
	float _Ki;
	float _Kd;
	float goal;
	float presentValue;
  float preTime;
  float preP=0;
  float reValue;
  float P;
  float I;
  float D;
  float dt;
  
};

#endif
