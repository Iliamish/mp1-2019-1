#include "Snake.h"

Snake::Snake()
{
	length = 0;
}


Snake::~Snake()
{
}

void Snake::AddTailSeg(COORD xy)
{
	if (length == 1)
		tail.push_back(xy);
	if (!length)
		tail.push_back(xy);
	if (length >= 2)
	{
		xy.X = 2 * tail[length - 1].X - tail[length - 2].X;
		xy.Y = 2 * tail[length - 1].Y - tail[length - 2].Y;
		tail.push_back(xy);
	}
	length++;
}

int Snake::GetLength()
{
	return length;
}

COORD Snake::GetSnakeHead()
{
	return tail.front();
}

COORD Snake::GetSnakeEnd()
{
	return tail.back();
}

vector<COORD> Snake::GetTail()
{
	return tail;
}

void Snake::Move(COORD headMove, int **matrix)
{
	matrix[tail[length - 1].Y][tail[length - 1].X] = 0;
	for (int i = length - 1; i > 0; i--)
	{
		tail[i] = tail[i - 1];
		matrix[tail[i].Y][tail[i].X] = 1;
	}
	tail[0].X += headMove.X;
	tail[0].Y += headMove.Y;
	matrix[tail[0].Y][tail[0].X] = 2;
}
