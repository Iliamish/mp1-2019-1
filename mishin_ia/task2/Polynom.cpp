#include "Polynom.h"

Polynom::Polynom(){}

Polynom::Polynom(int deg):Deg(deg){}

Polynom::Polynom(int deg, int coefs[13]): Deg(deg)
{
	int k = 0;
	while (coefs[k++] == 0)
		Deg--;
	for (int i = 0; i < Deg + 1; i++)
		Coef[i] = coefs[i];
}

Polynom::~Polynom()
{
	cout << "\nPolynom deleted";
}

void Polynom::SetCoefs(int*coefs)
{
	for (int i = 0; i < Deg + 1; i++)
		Coef[i] = coefs[i];
}

int * Polynom::GetCoefs()
{
	return Coef;
}

void Polynom::SetChosenCoef(int deg, int coef)
{
	Coef[Deg - deg] = coef;
}

int Polynom::GetChosenCoef(int deg)
{
	return Coef[Deg - deg];
}

int Polynom::GetDeg()
{
	return Deg;
}

void Polynom::printPolynom()
{
	cout << '\n' << Coef[0] << '*' << "x^" << Deg;
	for (int i = 1; i < Deg; i++)
		if (Coef[i] > 0)
			cout << '+' << Coef[i] << '*' << "x^" << Deg - i;
		else
			if (Coef[i] < 0)
				cout << Coef[i] << '*' << "x^" << Deg - i;
	if (Coef[Deg] > 0)
		cout << '+' << Coef[Deg];
	else
		cout << Coef[Deg];
}

double Polynom::value(double x)
{
	double value = Coef[Deg];
	for (int i = 0; i < Deg; i++)
		value += pow(x, Deg - i) * Coef[i];
	return value;
}

void Polynom::derivate()
{
	for (int i = 0; i < Deg + 1; i++)
		Coef[i] *= (Deg - i);
	Coef[Deg] = 0;
	Deg--;
}

Polynom Polynom::operator=(const Polynom & poly)
{
	this->Deg = poly.Deg;
	for (int i = 0; i < Deg + 1; i++)
		this->Coef[i] = poly.Coef[i];
	return *this;
}
