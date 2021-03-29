#pragma once
#include "MotorDriver.h"


//PWMの設定
const int PWM_Hz = 20000; //PWM周波数
const int PWM_Max = 255;
const int PWM_level = 8; //PWMの段階（8ならMAX２５５，１０なら１０２３）
const int PWMCH1 = 0; //チャンネル
const int PWMCH2 = 1;

MotorDriver::MotorDriver(uint8_t pin1, uint8_t pin2)
{
  _pin1 = pin1;
  _pin2 = pin2;

	pinMode(_pin1, OUTPUT);
	pinMode(_pin2, OUTPUT);
 //モータのPWMのチャンネル、周波数の設定
  ledcSetup(PWMCH1, PWM_Hz, PWM_level);
  ledcSetup(PWMCH2, PWM_Hz, PWM_level);
 
  //モータのピンとチャンネルの設定
  ledcAttachPin(_pin1, PWMCH1);
  ledcAttachPin(_pin2, PWMCH2);

	digitalWrite(_pin1, LOW);
	digitalWrite(_pin2, LOW);

}

void MotorDriver::setSpeed(float speed)
{
	if (speed > PWM_Max) {
		speed = PWM_Max;
	}
	else if (speed < -PWM_Max) {
		speed = -PWM_Max;
	}

  if (speed >= 0) {
    ledcWrite(PWMCH1, speed);
    ledcWrite(PWMCH2, 0);
  }else{
    ledcWrite(PWMCH1, 0);
    ledcWrite(PWMCH2, -speed);
	}
}
void MotorDriver::brake()
{
    ledcWrite(PWMCH1, 0);
    ledcWrite(PWMCH2, 0);
}

void MotorDriver::coast()
{
    ledcWrite(PWMCH1, PWM_Max);
    ledcWrite(PWMCH2, PWM_Max);
}
