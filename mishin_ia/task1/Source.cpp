#include <iostream>
#include <conio.h>
using namespace std;

class rationalFraction
{
	int Nominator;
	int Denominator;
public:
	rationalFraction()
	{

	}
	rationalFraction(int nominator, int denominator)
	{
		Nominator = nominator;
		Denominator = denominator;
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
};

int NOD(int x, int y)
{
	int div;
	if (y == x)  return y;
	int d = y - x;
	if (d < 0) {
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

rationalFraction add(rationalFraction rat1, rationalFraction rat2)
{
	rationalFraction rat3;
	int nok = NOK(rat1.getDenominator(), rat2.getDenominator());
	rat3.setDenominator(nok);
	rat3.setNominator(rat1.getNominator()*nok / rat1.getDenominator() +
					  rat2.getNominator()*nok / rat2.getDenominator());
	rat3.reduce();
	return rat3;
}

rationalFraction subtract(rationalFraction rat1, rationalFraction rat2)
{
	rationalFraction rat3;
	int nok = NOK(rat1.getDenominator(), rat2.getDenominator());
	rat3.setDenominator(nok);
	rat3.setNominator(rat1.getNominator()*nok / rat1.getDenominator() -
					  rat2.getNominator()*nok / rat2.getDenominator());
	rat3.reduce();
	return rat3;
}

rationalFraction multiplicate(rationalFraction rat1, rationalFraction rat2)
{
	rationalFraction rat3;
	rat3.setDenominator(rat1.getDenominator() * rat2.getDenominator());
	rat3.setNominator(rat1.getNominator() * rat2.getNominator());
	rat3.reduce();
	return rat3;
}

rationalFraction dimention(rationalFraction rat1, rationalFraction rat2)
{
	rationalFraction rat3;
	rat3.setDenominator(rat1.getDenominator() * rat2.getNominator());
	rat3.setNominator(rat1.getNominator() * rat2.getDenominator());
	rat3.reduce();
	return rat3;
}


int main()
{
	_getch();
}
