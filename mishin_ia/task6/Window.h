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
	
	int SideLength;
	
	void setWindow(int width);
public:
	Window(int sideLength);
	~Window();
	void gotoxy(int x, int y);
	COORD WhereXY(void);
	int GetSideLenght();
	void setBorder();
	void cleanWindow(int **Matrix);
	void printSnake(int **Matrix);
	
};

