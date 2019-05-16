#include "Window.h"

#define HEAD "#"
#define SEG "+"
#define FOOD "@"
#define up_border_element  '-'
#define side_border_element  '|'

Window::Window(int sideLength): sideLength(sideLength)
{
	SetWindow(sideLength + 1);
}


Window::~Window()
{
}

void Window::SetBorder()
{
	int k = 0;
	for (int i = 0; i <= sideLength; i++)
	{
		Gotoxy(i, k);
		cout << up_border_element;
		Gotoxy(k, i);
		cout << side_border_element;
	}
	k = sideLength;
	for (int i = 0; i <= sideLength ; i++)
	{
		Gotoxy(i, k);
		cout << up_border_element;
		Gotoxy(k, i);
		cout << side_border_element;
	}
}

void Window::CleanField(int **matrix)
{
	for (int i = 1; i < sideLength; i++)
	{
		for (int j = 1; j < sideLength; j++)
			if (matrix[i][j] == 1)
			{
				Gotoxy(i, j);
				cout << ' ';
			}
	}
}

void Window::PrintField(int **matrix)
{
	for (int i = 1; i < sideLength; i++)
	{
		Gotoxy(1, i);
		for (int j = 1; j < sideLength; j++)
			switch (matrix[i][j])
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
	return sideLength;
}

void Window::Gotoxy(int x, int y)
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

void Window::SetWindow(int width)
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
