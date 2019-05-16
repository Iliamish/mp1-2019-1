#include "Game.h"
#include <cmath>

int main()
{
	Snake snake;
	Window window(20);
	Game game(window, snake, window.GetSideLenght());
	game.StartGame();
	_getch();
}