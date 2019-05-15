#include "Window.h"

#define HEAD "#"
#define SEG "+"
#define FOOD "@"
#define up_border_element  '-'
#define side_border_element  '|'

Window::Window(int sideLength): SideLength(sideLength)
{
	setWindow(sideLength + 1);
}


Window::~Window()
{
}

void Window::setBorder()
{
	int k = 0;
	for (int i = 0; i <= SideLength; i++)
	{
		gotoxy(i, k);
		cout << up_border_element;
		gotoxy(k, i);
		cout << side_border_element;
	}
	k = SideLength;
	for (int i = 0; i <= SideLength ; i++)
	{
		gotoxy(i, k);
		cout << up_border_element;
		gotoxy(k, i);
		cout << side_border_element;
	}
}

void Window::cleanWindow(int **Matrix)
{
	for (int i = 1; i < SideLength; i++)
	{
		for (int j = 1; j < SideLength; j++)
			if (Matrix[i][j] == 1)
			{
				gotoxy(i, j);
				cout << ' ';
			}
	}
}

void Window::printSnake(int **Matrix)
{
	for (int i = 1; i < SideLength; i++)
	{
		gotoxy(1, i);
		for (int j = 1; j < SideLength; j++)
			switch (Matrix[i][j])
			{
			case(0): cout << " "; break;
			case(1): cout << SEG; break;
			case(2): cout << HEAD; break;
				//case(3): cout << "o"; break;
			case(9): cout << FOOD; break;
			default:
				break;
			}
	}
}

int Window::GetSideLenght()
{
	return SideLength;
}

void Window::gotoxy(int x, int y)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!Console)
		return;
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(Console, pos);
}

COORD Window::WhereXY(void)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { -1, -1 };
	if (!Console)
		return pos;
	CONSOLE_SCREEN_BUFFER_INFO buf;
	GetConsoleScreenBufferInfo(Console, &buf);
	return buf.dwCursorPosition;
}

void Window::setWindow(int width)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!Console)
		return;
	SMALL_RECT rect;
	rect.Left = 0;
	rect.Right = width;
	rect.Top = 0;
	rect.Bottom = width;
	COORD size;
	size.X = width;
	size.Y = width;
	SetConsoleWindowInfo(Console, true, &rect);
	SetConsoleScreenBufferSize(Console, size);
}
