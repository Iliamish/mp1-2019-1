#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Polynom
{
	int Deg;
	int Coef[13]; // coefs from higest degree[0] to free coef[Deg]
public:
	Polynom();
	Polynom(int deg);
	Polynom(int deg, int coefs[13]);
	~Polynom();
	void SetCoefs(int*coefs);
	int* GetCoefs();
	void SetChosenCoef(int deg, int coef);
	int GetChosenCoef(int deg);
	int GetDeg();
	void printPolynom();
	double value(double x);
	void derivate();
	Polynom operator=(const Polynom &poly);
};


