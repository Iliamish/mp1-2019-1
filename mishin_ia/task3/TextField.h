#pragma once
#include <windows.h>
#include <memory.h>
using namespace std;

class TextField
{
	int Length;
	int X;
	int Y;
	void gotoxy(int x, int y);
	void textbackground(int color);
	COORD WhereXY(void);
	void setwindow(int width, int height);
public:
	TextField(int x = 0, int y = 0, int length = 0);
	~TextField();
	void SetLen(int length);
	int GetLen();
	void SetX(int x);
	int GetX();
	void SetY(int y);
	int GetY();
	void PutFieldOnConsole();
	int wherex();
};

