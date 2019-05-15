#pragma once
#include <vector>
#include <cmath>
#include <windows.h>
using std::vector;

class Snake
{
	
	int Length;
	vector<COORD> tail;
public:
	Snake();
	~Snake();
	void addTailSeg(COORD xy);
	COORD GetSnakeHead();
	COORD GetSnakeEnd();
	vector<COORD> GetTail();
	void Move(COORD HeadMove, int **Matrix);
};

