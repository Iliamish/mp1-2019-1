#pragma once
#include "Snake.h"
#include <iostream>
#include <windows.h>
#include <memory.h>
#include <string>
using std::string;
using std::cout;

class Window
{
	int sideLength;

	void SetWindow(int width);
public:
	Window(int sideLength);
	~Window();
	void Gotoxy(int x, int y);
	COORD WhereXY(void);
	int GetSideLenght();
	void SetBorder();
	void CleanField(int **matrix);
	void PrintField(int **matrix);
};

