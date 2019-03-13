#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include "TextField.h"

class TextEditor
{
	TextField Field;
	string Text;
	int startpoint;
public:
	TextEditor(TextField &field);
	~TextEditor();
	string GetText();
	void in();
};

