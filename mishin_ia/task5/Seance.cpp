#include "Seance.h"



Seance::Seance()
{
}

Seance::Seance(string date, string time, string name, Hall hall):
				Date(date), Time(time), Name(name), hall(hall)
{
}


Seance::~Seance()
{
}

string Seance::GetName()
{
	return Name;
}

string Seance::GetDate()
{
	return Date;
}

string Seance::GetTime()
{
	return Time;
}

Hall Seance::GetHall()
{
	return hall;
}
