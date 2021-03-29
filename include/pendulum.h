#pragma once
#include "PID.h"

namespace pen{

class pendulum : public PID{
PID pid;

private:
    float Kx,Kv;
    int preTime;
    double newX, preX;
public:
    pendulum(float Kp, float Ki, float Kd, float _Kx, float _Kv);
    double update(const int roll, const int enc);
};

pendulum::pendulum(float Kp, float Ki, float Kd, float _Kx, float _Kv) : pid(Kp, Ki, Kd)
{
    Kx = _Kx;
    Kv = _Kv;
    preTime = micros();
}

double pendulum::update(const int roll, const int enc)
{
    double dt = (micros() - preTime) / 1000000;
    preTime = micros();
    double v = (newX - preX)/dt;
    
    preX = newX;

    double result = pid.pid( 6, roll) + Kx*newX + Kv*v;
}

}//end namespace