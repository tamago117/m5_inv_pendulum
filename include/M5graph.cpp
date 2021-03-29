#pragma once
#include "M5graph.h"
#include "M5Stack.h"


void M5graph::graph(float _roll)
{
  roll=_roll;
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
