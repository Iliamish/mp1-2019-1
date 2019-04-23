#pragma once
#include "Hall.h"
#include <string>
using std::string;
using std::vector;

struct Ticket {
	string Date;
	string Time;
	string Name;
	int HallNumber;
	int Row;
	int Col;
	double Cost;
};

class Seance
{
	Hall hall;
	string Date;
	string Time;
	string Name;
public:
	Seance();
	Seance(string date, string time, string name, Hall hall);
	~Seance();
	
	string GetName();
	string GetDate();
	string GetTime();
	Hall GetHall();
};

