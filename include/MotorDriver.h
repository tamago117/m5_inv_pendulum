#ifndef MotorDriver_H
#define MotorDriver_H

#include <arduino.h>
#include <stdint.h>

class MotorDriver
{
public:
	MotorDriver(uint8_t pin1, uint8_t pin2);
	void setSpeed(float speed);
  void brake();
  void coast();

protected:
	uint8_t _pin1;
	uint8_t _pin2;
};

#endif
