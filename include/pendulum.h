#pragma once
#include "PID.h"

namespace pen{

class pendulum : public PID{
//PID pid;

private:
    float Kx,Kv;
    int preTime;
    double newX;
    double preX = 0;
public:
    pendulum(float Kp, float Ki, float Kd, float _Kx, float _Kv);
    double update(const double tarValue ,const double tarXValue ,const int roll, const int enc);
};

pendulum::pendulum(float Kp, float Ki, float Kd, float _Kx, float _Kv) : PID(Kp, Ki, Kd), Kx(_Kx), Kv(_Kv)
{
    preTime = micros();
}

double pendulum::update(const double tarRollValue, const double tarXValue, const int roll, const int enc)
{
    newX = tarXValue - enc; 
    double dt = (micros() - preTime) / 1000000;
    preTime = micros();
    double v = (newX - preX)/dt;
    
    preX = newX;

    double result = PID::update(tarRollValue, roll) + Kx*newX + Kv*v;
}

}//end namespace