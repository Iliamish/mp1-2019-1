#include "TextField.h"

enum TColor 
{
	BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY,
	DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED,
	LIGHTMAGENTA, YELLOW, WHITE
};

void TextField::gotoxy(int x, int y)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!Console)
		return;
	COORD pos;
	pos.X = x;
	pos.Y = y;		
	SetConsoleCursorPosition(Console, pos);
}

int TextField::wherex()
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!Console)
		return -1;
	CONSOLE_SCREEN_BUFFER_INFO buf;
	GetConsoleScreenBufferInfo(Console, &buf);
	return buf.dwCursorPosition.X;
}

void TextField::textbackground(int color)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!Console)
		return;
	CONSOLE_SCREEN_BUFFER_INFO buf;
	GetConsoleScreenBufferInfo(Console, &buf);
	WORD Attr;
	DWORD Count;
	COORD pos = buf.dwCursorPosition;
	ReadConsoleOutputAttribute(Console, &Attr, 1, pos, &Count);
	int text_col = Attr % 16;
	int col = color % 16;
	col = color * 16 + text_col;
	SetConsoleTextAttribute(Console, col);
	char ch;
	pos = WhereXY();
	ReadConsoleOutputCharacter(Console, &ch, 1, pos, &Count);
	gotoxy(pos.X, pos.Y);
}

COORD TextField::WhereXY(void)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { -1, -1 };
	if (!Console)
		return pos;
	CONSOLE_SCREEN_BUFFER_INFO buf;
	GetConsoleScreenBufferInfo(Console, &buf);
	return buf.dwCursorPosition;
}

void TextField::setwindow(int width, int height)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!Console)
		return;
	SMALL_RECT rect;
	rect.Left = 0;
	rect.Right = width - 1;
	rect.Top = 0;
	rect.Bottom = height - 1;
	COORD size;
	size.X = width;
	size.Y = height;
	SetConsoleWindowInfo(Console, true, &rect);
	SetConsoleScreenBufferSize(Console, size);
}

TextField::TextField(int x, int y, int length) : X(x), Y(y), Length(length)
{

}


TextField::~TextField()
{

}

void TextField::SetLen(int length)
{
	Length = length;
}

int TextField::GetLen()
{
	return Length;
}

void TextField::SetX(int x)
{
	X = x;
}

int TextField::GetX()
{
	return X;
}

void TextField::SetY(int y)
{
	Y = y;
}

int TextField::GetY()
{
	return Y;
}

void TextField::PutFieldOnConsole()
{
	gotoxy(X, Y);
	system("cls");
	textbackground(BLUE);
}
