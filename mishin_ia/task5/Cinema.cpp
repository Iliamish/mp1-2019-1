#include "Cinema.h"

Cinema::Cinema()
{
	UpdateHalls();
	UpdateSeances();
}


Cinema::~Cinema()
{
}

void Cinema::UpdateSeances()
{
	//read seances from file
}

void Cinema::UpdateHalls()
{
	//read halls from file
}

vector<Seance> Cinema::GetSeances(string date)
{
	int days[13] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	vector<Seance> seances;
	for (Seance seance : Seances)
	{
		if (days[std::stoi(date.substr(6, 7))] - std::stoi(date.substr(8, 9)) >= 3)
		{
			if (std::stoi(seance.GetDate().substr(8, 9)) - 3 <= std::stoi(date.substr(8, 9)))
				seances.push_back(seance);
		}
		else
			if ((std::stoi(seance.GetDate().substr(8, 9)) + std::stoi(date.substr(8, 9))) % days[std::stoi(date.substr(6, 7))] < 3)
				seances.push_back(seance);
		//return seances for nearest 3 days
	}
	return seances;
}

Hall Cinema::GetHall(int number)
{
	return Halls[number];
}
