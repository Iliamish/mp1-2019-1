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
	int wherex, len = Field.GetLen();
	ch = _getch();
	while (ch != 13)
	{
		wherex = Field.wherex();
		if ((wherex - x < len) && (wherex >= x + 1))
		{
			if (ch == '\b' && Text.length() > 0)
			{
				Text.pop_back();
				cout << "\b \b";
			}
			else
			{
				Text.push_back(ch);
				cout << ch;
			}
		}
		else
		{
			if (wherex != x)
			{
				if (ch == '\b')
				{
					Text.pop_back();
					cout << "\b \b";
				}
			}
			else
				if (ch != '\b')
				{
					Text.push_back(ch);
					cout << ch;
				}
		}
		ch = _getch();
	}
}
