#pragma once
#include "Snake.h"
#include "Window.h"
#include <iostream>
#include <conio.h>
#include <time.h>

using std::cout;

class Game
{
	Window Win;
	Snake snake;
	int **Matrix;
	int SideLength;
	COORD Food;
	char Movekey;
	COORD HeadMove;
	int getRand();
	bool checkRand(int a , bool t);
	int GameSpeed;
	int Points;
public:
	Game(Window Win, Snake snake, int sideLength);
	~Game();
	void startGame();
	bool gameOver();
	void tick();
	void generateFood();
};

