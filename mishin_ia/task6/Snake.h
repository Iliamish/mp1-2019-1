#pragma once
#include <vector>
#include <cmath>
#include <windows.h>
using std::vector;

class Snake
{
	int length;
	vector<COORD> tail;
public:
	Snake();
	~Snake();
	void AddTailSeg(COORD xy);
	int GetLength();
	COORD GetSnakeHead();
	COORD GetSnakeEnd();
	vector<COORD> GetTail();
	void Move(COORD headMove, int **matrix);
};

