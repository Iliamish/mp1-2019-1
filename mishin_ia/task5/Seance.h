#pragma once
#include "Hall.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

class Seance
{
	Hall *Hall;
	typedef struct SeanseTime
	{
		string Date;
		string Time;
	}SeanseTime;
	string Name;
public:
	Seance();
	~Seance();
};

