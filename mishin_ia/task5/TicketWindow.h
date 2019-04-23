#pragma once
#include "Seance.h"
#include "Cinema.h"

class TicketWindow
{
	vector<Seance> Seances;
public:
	TicketWindow();
	~TicketWindow();

	string RealTime();

	bool BuyTicket(string date, string time, string name, int hallNumber, int type, int seatsNum, vector<Ticket> &tickets);
	bool ReturnTicket(vector<Ticket> &tickets);
};

