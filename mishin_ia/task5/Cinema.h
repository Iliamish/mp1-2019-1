#pragma once
#include "Seance.h"
#include <vector>

class Cinema
{
	vector<Seance> Seances;
	vector<Hall> Halls;
public:
	Cinema();
	~Cinema();
	
	void UpdateSeances();
	void UpdateHalls();

	vector<Seance> GetSeances(string date);
	Hall GetHall(int number);
};

