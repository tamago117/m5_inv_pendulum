#pragma once
#include "M5Stack.h"
#include <vector>

namespace M5view{

const int offsetY = 100;
const int lcdX = 320;

class M5graph
{
public:
	void graph(const float roll);

private:
	float roll;
	std::vector<float> rollY[lcdX];
};

void M5graph::graph(const float roll)
{
	M5.Lcd.fillScreen(BLACK);

	M5.Lcd.setCursor(0, 200);
  	M5.Lcd.print(roll);
	rollY[lcdX] = roll + offsetY;
	for (int i = 0; i <= lcdX; i++) {
		rollY[i] = rollY[i + 1];
		M5.Lcd.drawPixel(i, rollY[i], RED);
    M5.Lcd.drawPixel(i, offsetY, GREEN);
	}
	//delay(1);
	M5.update();
}
}//end namespace
