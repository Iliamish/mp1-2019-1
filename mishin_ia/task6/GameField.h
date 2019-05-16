#pragma once
class GameField
{
	int **matrix;
	int sideLength;
public:
	GameField();
	GameField(int sideLength);
	~GameField();
	int** GetMatrix();
};

