#include "TextEditor.h"


int main()
{
	TextField tf(20, 20, 20);
	tf.PutFieldOnConsole();
	TextEditor editor(tf);
	editor.in();
	system("cls");
	cout << editor.GetText();
	_getch();
}

