#include "TextEditor.h"

TextEditor::TextEditor(TextField &field):Field(field)
{
	startpoint = Field.GetX();
}


TextEditor::~TextEditor()
{
}

string TextEditor::GetText()
{
	return Text;
}

void TextEditor::in()
{
	char ch = 0;
	int x = Field.GetX();
	ch = _getch();
	while (ch != 13)
	{
		if ((Field.wherex() - Field.GetX() < Field.GetLen()) && ch != 13)
		{
			cout << ch;
			if (ch == '\b')
			{
				Text.pop_back();
				cout << " \b";
			}
			Text.push_back(ch);
		}
		else
		{
			if (ch == '\b')
			{
				Text.pop_back();
				cout << " \b";
			}
		}
		ch = _getch();
		_getch();
	}
}
