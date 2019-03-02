#pragma once
#include <iostream>
#include <cmath>
#include <regex>
#include <string>
using namespace std;

class Polynom
{
	int Deg = 0;
	int Coef[13] = { 0 }; // coefs from higest degree[0] to free coef[Deg]
public:
	Polynom();
	Polynom(int deg);
	Polynom(int deg, int coefs[13]);
	Polynom(string poly);
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


