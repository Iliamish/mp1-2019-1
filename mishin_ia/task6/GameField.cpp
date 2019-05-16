#include "GameField.h"



GameField::GameField()
{
}

GameField::GameField(int sideLength):sideLength(sideLength)
{
	sideLength++;
	this->matrix = new int *[sideLength];
	for (int i = 0; i < sideLength; i++)
	{
		matrix[i] = new int[sideLength];
	}
	for (int i = 0; i < sideLength; i++)
		for (int j = 0; j < sideLength; j++)
			matrix[i][j] = 0;
}


GameField::~GameField()
{
}

int ** GameField::GetMatrix()
{
	return matrix;
}
