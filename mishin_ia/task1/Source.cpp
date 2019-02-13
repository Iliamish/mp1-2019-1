#include <iostream>
#include <conio.h>
using namespace std;

int NOD(int x, int y)
{
	int div;
	if (y == x)  return y;
	int d = y - x;
	if (d < 0)
	{
		d = -d;  div = NOD(y, d);
	}
	else
		div = NOD(x, d);
	return div;
}

int NOK(int x, int y)
{
	return x * y / NOD(x, y);
}

class rationalFraction
{
	int Nominator;
	int Denominator;
public:
	rationalFraction()
	{

	}
	rationalFraction(int nominator, int denominator):Nominator(nominator),Denominator(denominator)
	{
		
	}
	void setNominator(int nominator)
	{
		Nominator = nominator;
	}
	char setDenominator(int denominator)
	{
		if (denominator != 0)
		{
			Denominator = denominator;
			return 1;
		}
		else
		{
			cout << "Error, zero divide exeption\n";
			return 0;
		}
	}
	int getNominator()
	{
		return Nominator;
	}
	int getDenominator()
	{
		return Denominator;
	}
	void reduce()
	{
		int min, k = 2;
		if (Denominator > Nominator)
			min = Nominator;
		else
			min = Denominator;
		while (k <= min)
		{
			if (Nominator % k == 0 && Denominator % k == 0)
			{
				Nominator /= k;
				Denominator /= k;
				min /= k;
			}
			else
				k++;
		}
	}
	void printFrac()
	{
		cout << Nominator << '/' << Denominator;
	}
	rationalFraction operator+(rationalFraction &rat)
	{
		rationalFraction rat2;
		int nok = NOK(this->Denominator, rat.getDenominator());
		rat2.setDenominator(nok);
		rat2.setNominator(this->Nominator * nok / (this->Denominator) +
						  rat.getNominator()*nok / rat.getDenominator());
		rat2.reduce();
		return rat2;
	}
	rationalFraction operator-(rationalFraction &rat)
	{
		rationalFraction rat2;
		int nok = NOK(this->Denominator, rat.getDenominator());
		rat2.setDenominator(nok);
		rat2.setNominator(this->Nominator * nok / (this->Denominator) -
						  rat.getNominator()*nok / rat.getDenominator());
		rat2.reduce();
		return rat2;
	}
	rationalFraction operator*(rationalFraction &rat)
	{
		rationalFraction rat2;
		rat2.setDenominator(this->Denominator * rat.getDenominator());
		rat2.setNominator(this->Nominator * rat.getNominator());
		rat2.reduce();
		return rat2;
	}
	rationalFraction operator/(rationalFraction &rat)
	{
		rationalFraction rat2;
		rat2.setDenominator(this->Denominator * rat.getNominator());
		rat2.setNominator(this->Nominator * rat.getDenominator());
		rat2.reduce();
		return rat2;
	}
};

int main()
{
	_getch();
}
