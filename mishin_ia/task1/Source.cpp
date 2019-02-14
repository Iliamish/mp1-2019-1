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
		cout << Nominator << '/' << Denominator<<"\n";
	}
	rationalFraction& operator=(const rationalFraction &rat)
	{
		Nominator = rat.Nominator;
		Denominator = rat.Denominator;
		return *this;
	}
	rationalFraction operator+(const rationalFraction &rat)
	{
		rationalFraction rat2;
		int nok = NOK(this->Denominator, rat.Denominator);
		rat2.Denominator = nok;
		rat2.Nominator = this->Nominator * nok / (this->Denominator) +
							   rat.Nominator*nok / rat.Denominator;
		rat2.reduce();
		return rat2;
	}
	friend rationalFraction operator + (const int &num, const rationalFraction &rat);
	friend rationalFraction operator + (const rationalFraction &rat, const int &num);
	rationalFraction operator-(const rationalFraction &rat)
	{
		rationalFraction rat2;
		int nok = NOK(this->Denominator, rat.Denominator);
		rat2.Denominator = nok;
		rat2.Nominator = this->Nominator * nok / (this->Denominator) -
						 rat.Nominator*nok / rat.Denominator;
		rat2.reduce();
		return rat2;
	}
	rationalFraction operator*(const rationalFraction &rat)
	{
		rationalFraction rat2;
		rat2.Denominator = this->Denominator * rat.Denominator;
		rat2.Nominator = this->Nominator * rat.Nominator;
		rat2.reduce();
		return rat2;
	}
	rationalFraction operator/(const rationalFraction &rat)
	{
		rationalFraction rat2;
		rat2.Denominator = this->Denominator * rat.Nominator;
		rat2.Nominator = this->Nominator * rat.Denominator;
		rat2.reduce();
		return rat2;
	}
};

rationalFraction operator+(const int &num, const rationalFraction &rat)
{
	rationalFraction rat2;
	rat2.Denominator = rat.Denominator;
	rat2.Nominator = rat.Nominator + rat.Denominator * num;
	rat2.reduce();
	return rat2;
}
rationalFraction operator+(const rationalFraction &rat, const int &num)
{
	rationalFraction rat2;
	rat2.Denominator = rat.Denominator;
	rat2.Nominator = rat.Nominator + rat.Denominator * num;
	rat2.reduce();
	return rat2;
}

int main()
{
	rationalFraction rat1(1, 2), rat2(3, 5), resultrat;
	resultrat = 10 + rat1 + 1 ;
	resultrat.printFrac();
	resultrat = rat1 - rat2;
	resultrat.printFrac();
	resultrat = rat1 * rat2;
	resultrat.printFrac();
	resultrat = rat1 / rat2;
	resultrat.printFrac();
	_getch();
}
