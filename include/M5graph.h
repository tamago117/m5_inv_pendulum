#pragma once

namespace M5view{
class M5graph
{
public:
	void graph(float roll);
	const int offsetY = 100;
	const int lcdX = 320;

private:
	float roll;
	float rollY[lcdX];
};

}
