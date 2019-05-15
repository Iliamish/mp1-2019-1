#include "Snake.h"



Snake::Snake()
{
	Length = 0;
}


Snake::~Snake()
{
}

void Snake::addTailSeg(COORD xy)
{
	if (Length == 1)
		tail.push_back(xy);
	if (!Length)
		tail.push_back(xy);
	if (Length >= 2)
	{
		xy.X = 2 * tail[Length - 1].X - tail[Length - 2].X;
		xy.Y = 2 * tail[Length - 1].Y - tail[Length - 2].Y;
		tail.push_back(xy);
	}
	Length++;
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

void Snake::Move(COORD HeadMove, int **Matrix)
{
	Matrix[tail[Length - 1].Y][tail[Length - 1].X] = 0;
	for (int i = Length - 1; i > 0; i--)
	{
		tail[i] = tail[i - 1];
		Matrix[tail[i].Y][tail[i].X] = 1;
	}
	tail[0].X += HeadMove.X;
	tail[0].Y += HeadMove.Y;
	Matrix[tail[0].Y][tail[0].X] = 2;
}
