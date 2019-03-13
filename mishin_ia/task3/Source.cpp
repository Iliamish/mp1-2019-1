#include "TextEditor.h"


int main()
{
	TextField tf(20, 20, 10);
	_getch();
	tf.PutFieldOnConsole();
	TextEditor editor(tf);
	editor.in();
	cout << editor.GetText();
	_getch();
}

