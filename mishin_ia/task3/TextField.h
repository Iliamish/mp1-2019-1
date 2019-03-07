#pragma once
#include <windows.h>
#include <memory.h>

class TextField
{
	int Length;
	int X;
	int Y;
public:
	TextField(int x = 0, int y = 0, int length = 0);
	~TextField();
	void SetLen(int length);
	int GetLen();
	int SetX(int x);
	void GetX();
	int SetY(int y);
	void GetY();
	void PutFieldOnConsole();

};

