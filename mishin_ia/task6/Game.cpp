#include "Game.h"
#define finalLength 50

Game::Game(Window window, Snake snake, int sideLength):win(window), snake(snake), sideLength(sideLength)
{
	sideLength++;
	points = 0;
	gameSpeed = 500;
	headMove = { 0,0 };
	srand(time(NULL));
	/*this->matrix = new int *[sideLength];
	for (int i = 0; i < sideLength; i++)
	{
		matrix[i] = new int[sideLength];
	}
	for (int i = 0; i < sideLength; i++)
		for (int j = 0; j < sideLength; j++)
			matrix[i][j] = 0;*/

	GameField field(sideLength);
	this->field = field;
		
	field.GetMatrix()[sideLength / 2][sideLength / 2] = 2;
	COORD xy = { sideLength / 2, sideLength / 2 };
	this->snake.AddTailSeg(xy);
	for (int i = 1; i < 3; i++)
	{
		field.GetMatrix()[sideLength / 2 ][sideLength / 2 - i] = 1;
		xy.X--;
		this->snake.AddTailSeg(xy);
	}
}


Game::~Game()
{
	/*for (int i = 0; i < sideLength; i++)
	{
		delete[] matrix[i];
	}*/
}

void Game::StartGame()
{
	win.SetBorder();
	GenerateFood();
	
	while (!GameOver())
	{
		Tick();
		Sleep(gameSpeed);
	}

	system("cls");
	win.Gotoxy(sideLength / 2 - 5, sideLength / 2);
	cout << "You Dead";
	win.Gotoxy(0,0);
}

bool Game::GameOver()
{
	if ((snake.GetSnakeHead().X == 0) || (snake.GetSnakeHead().X == sideLength) ||
		(snake.GetSnakeHead().Y == 0) || (snake.GetSnakeHead().Y == sideLength))
		return true;
	vector<COORD> tail = snake.GetTail();
	bool flag = 1;

	for (COORD seg : tail)
	{
		if (snake.GetSnakeHead().X == seg.X && snake.GetSnakeHead().Y == seg.Y)
			if (flag)
				flag = 0;
			else
				return true;
	}
	if (snake.GetLength() == finalLength)
	{
		system("cls");
		win.Gotoxy(sideLength / 2 - 5, sideLength / 2);
		cout << "You Win";
		win.Gotoxy(0, 0);
		_getch();
		return true;
	}
	return false;
}

void Game::Tick()
{
	win.CleanField(field.GetMatrix());
		
	if (_kbhit())
	{
		_getch();
		moveKey = int(_getch());
	}
	switch (int(moveKey))
	{
	case(80):
		if(headMove.X != 0 || headMove.Y != -1)
			headMove = { 0,1 };
		break;
	case(72):
		if (headMove.X != 0 || headMove.Y != 1)
			headMove = { 0,-1 };
		break;
	case(75):
		if (headMove.X != 1 || headMove.Y != 0)
			headMove = { -1,0 };
		break;
	case(77):
		if (headMove.X != -1 || headMove.Y != 0)
			headMove = { 1,0 };
		break;
	case(int('s')):
		gameSpeed -= 5;
		break;
	default:
		break;
	}
	
	if (headMove.X != 0 || headMove.Y != 0)
		snake.Move(headMove, field.GetMatrix());

	if (food.X == snake.GetSnakeHead().X && food.Y == snake.GetSnakeHead().Y)
	{
		points += 100;
		win.Gotoxy(0, 0);
		cout << points;
		snake.AddTailSeg({ 0,0 });
		GenerateFood();
		if (points % 1000 == 0)
		{
			gameSpeed -= 50;
		}
	}
	win.PrintField(field.GetMatrix());
}

void Game::GenerateFood()
{
	int x = GetRand();
	int y = GetRand();

	while (!CheckRand(x, 1))
		x = GetRand();
	food.X = x;

	while (!CheckRand(y, 0))
		y = GetRand();
	food.Y = y;

	field.GetMatrix()[food.Y][food.X] = 9;
}

int Game::GetRand()
{
	return rand() % (sideLength - 1) + 1;
}

bool Game::CheckRand(int a, bool t)
{
	vector<COORD> tail = snake.GetTail();
	if (t)
	{
		for (COORD seg : tail)
			if (seg.X == a)
				return false;
	}
	else
		for (COORD seg : tail)
			if (seg.Y == a)
				return false;
	return true;
}


