#pragma once
#include <iostream>
#include "TextField.h"


class TextEditor : public TextField
{
	TextField Field;
public:
	TextEditor(TextField field);
	~TextEditor();
};

