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
	while ((Field.wherex() - Field.GetX() < Field.GetLen()) && ch != 13)
	{
		ch = _getche();
		Text += ch;
	}
}
