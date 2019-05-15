#include "Game.h"
#include <cmath>

int main()
{
	Snake snake;
	Window window(20);
	Game game(window, snake, window.GetSideLenght());// исправить третий параметр
	game.startGame();
	_getch();
}