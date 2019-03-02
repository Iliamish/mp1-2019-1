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

Polynom::Polynom(string poly)
{
	smatch m, dg, cf;
	regex e("([+-]?[^+-]+)"); 
	regex coef("([+-]?\\d+x)");
	regex deg("([\\^]\\d+)");
	regex freecoef("[+-]?\\d+");

	string mony, degree, coef_x;
	
	while (regex_search(poly, m, e)) 
	{
		int k = 0, coeffi = 0;
		mony = m.str();
		if(regex_search(mony, dg, deg))
		{
			degree = dg.str();
			for (int i = 1; i < degree.length(); i++)
				k += (degree[i] - '0') * pow(10, degree.length() - i - 1);
			if(Deg == 0)
				Deg = k;
			regex_search(mony, cf, coef);
			coef_x = cf.str();
			int sign = 1;
			if (coef_x[0] == '-')
				for (int i = 1; i < coef_x.length() - 1; i++)
					coeffi -= (coef_x[i] - '0') * pow(10, coef_x.length() - i - 2);
			else
				if(coef_x[0] > '0' && coef_x[0] <= '9')
					for (int i = 0; i < coef_x.length()-1; i++)
						coeffi += (coef_x[i] - '0') * pow(10, coef_x.length() - i - 2);
				else
					for (int i = 1; i < coef_x.length() - 1; i++)
						coeffi +=(coef_x[i] - '0') * pow(10, coef_x.length() - i - 2);
			Coef[Deg - k] = coeffi;
		}
		else
		{
			if (regex_search(mony, cf, coef))
			{
				if (Deg == 0)
					Deg = 1;
				coef_x = cf.str();
				if (coef_x[0] == '-')
					for (int i = 1; i < coef_x.length() - 1; i++)
						coeffi -= (coef_x[i] - '0') * pow(10, coef_x.length() - i - 2);
				else
					if (coef_x[0] > '0' && coef_x[0] <= '9')
						for (int i = 0; i < coef_x.length() - 1; i++)
							coeffi += (coef_x[i] - '0') * pow(10, coef_x.length() - i - 2);
					else
						for (int i = 1; i < coef_x.length() - 1; i++)
							coeffi += (coef_x[i] - '0') * pow(10, coef_x.length() - i - 2);
				Coef[Deg - 1] = coeffi;
			}
			else
			{
				regex_search(mony, cf, freecoef);
					coef_x = cf.str();
				if (coef_x[0] == '-')
					for (int i = 1; i < coef_x.length(); i++)
						coeffi -= (coef_x[i] - '0') * pow(10, coef_x.length() - i - 1);
				else
					if (coef_x[0] > '0' && coef_x[0] <= '9')
						for (int i = 0; i < coef_x.length(); i++)
							coeffi += (coef_x[i] - '0') * pow(10, coef_x.length() - i - 1);
					else
						for (int i = 1; i < coef_x.length(); i++)
							coeffi += (coef_x[i] - '0') * pow(10, coef_x.length() - i - 1);
				Coef[Deg] = coeffi;
			}
		}
		poly = m.suffix().str();
	}
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
	if(Deg != 0)
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
