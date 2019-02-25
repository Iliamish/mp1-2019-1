#include "Polynom.h"
#include <conio.h>

int main()
{
	int coefs[] = { 1,2,3,4,-5 };
	Polynom poly(4, coefs);
	poly.derivate();
	poly.printPolynom();
	_getch();
}