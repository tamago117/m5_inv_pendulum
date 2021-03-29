#ifndef M5graph_H
#define M5graph_H

const int lcdX = 320;

class M5graph
{
public:
	void graph(float roll);

private:
	float roll;
	float rollY[lcdX];
};

#endif
