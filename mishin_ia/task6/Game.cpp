#include "Game.h"


Game::Game(Window window, Snake snake, int sideLength):Win(window), snake(snake), SideLength(sideLength)
{
	sideLength++;
	Points = 0;
	GameSpeed = 500;
	HeadMove = { 0,0 };
	srand(time(NULL));
	this->Matrix = new int *[sideLength];
	for (int i = 0; i < sideLength; i++)
	{
		Matrix[i] = new int[sideLength];
	}
	for (int i = 0; i < sideLength; i++)
		for (int j = 0; j < sideLength; j++)
			Matrix[i][j] = 0;

	
	Matrix[sideLength / 2][sideLength / 2] = 2;
	COORD xy = { sideLength / 2, sideLength / 2 };
	this->snake.addTailSeg(xy);
	for (int i = 1; i < 3; i++)
	{
		Matrix[sideLength / 2 ][sideLength / 2 - i] = 1;
		xy.X--;
		this->snake.addTailSeg(xy);
	}
}


Game::~Game()
{
	for (int i = 0; i < SideLength; i++)
	{
		delete[] Matrix[i];
	}
}

void Game::startGame()
{
	Win.setBorder();
	generateFood();
	
	while (!gameOver())
	{
		tick();
		Sleep(GameSpeed);
	}

	system("cls");
	Win.gotoxy(SideLength / 2 - 5, SideLength / 2);
	cout << "You Dead";
	Win.gotoxy(0,0);
}

bool Game::gameOver()
{
	if ((snake.GetSnakeHead().X == 0) || (snake.GetSnakeHead().X == SideLength) ||
		(snake.GetSnakeHead().Y == 0) || (snake.GetSnakeHead().Y == SideLength))
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
	return false;
}

void Game::tick()
{
	Win.cleanWindow(Matrix);
		
	if (_kbhit())
	{
		_getch();
		Movekey = int(_getch());
	}
	switch (int(Movekey))
	{
	case(80):
		if(HeadMove.X != 0 || HeadMove.Y != -1)
			HeadMove = { 0,1 };
		break;
	case(72):
		if (HeadMove.X != 0 || HeadMove.Y != 1)
			HeadMove = { 0,-1 };
		break;
	case(75):
		if (HeadMove.X != 1 || HeadMove.Y != 0)
			HeadMove = { -1,0 };
		break;
	case(77):
		if (HeadMove.X != -1 || HeadMove.Y != 0)
			HeadMove = { 1,0 };
		break;
	case(int('s')):
		GameSpeed -= 5;
		break;
	default:
		break;
	}
	
	if (HeadMove.X != 0 || HeadMove.Y != 0)
		snake.Move(HeadMove, Matrix);

	if (Food.X == snake.GetSnakeHead().X && Food.Y == snake.GetSnakeHead().Y)
	{
		Points += 100;
		Win.gotoxy(0, 0);
		cout << Points;
		snake.addTailSeg({ 0,0 });
		generateFood();
		if (Points % 1000 == 0)
		{
			GameSpeed -= 50;
		}
	}
	Win.printSnake(Matrix);
}

void Game::generateFood()
{
	int x = getRand();
	int y = getRand();

	while (!checkRand(x, 1))
		x = getRand();
	Food.X = x;

	while (!checkRand(y, 0))
		y = getRand();
	Food.Y = y;

	Matrix[Food.Y][Food.X] = 9;
}

int Game::getRand()
{
	return rand() % (SideLength - 1) + 1;
}

bool Game::checkRand(int a, bool t)
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


