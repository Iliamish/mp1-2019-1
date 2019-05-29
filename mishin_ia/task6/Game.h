#pragma once
#include "Snake.h"
#include "Window.h"
#include <iostream>
#include <conio.h>
#include <time.h>

using std::cout;

class Game
{
	Window win;
	Snake snake;
	int **matrix;
	int sideLength;
	int gameSpeed;
	int points;
	COORD food;
	char moveKey;
	COORD headMove;
	
	int GetRand();
	bool CheckRand(int a, bool t);
public:
	Game(Window win, Snake snake, int sideLength);
	~Game();
	void StartGame();
	bool GameOver();
	void Tick();
	void GenerateFood();
};

