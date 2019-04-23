#include "TicketWindow.h"



TicketWindow::TicketWindow()
{
	Cinema cinema;
	Seances = cinema.GetSeances("2019_04_21"); // " year_month_day "
}


TicketWindow::~TicketWindow()
{
}

string TicketWindow::RealTime()
{
	//return "date + (real clock time + 10 minutes)" , for check if time between seance and real time less than 10 minutes
	return string();
}

bool TicketWindow::BuyTicket(string date, string time, string name, int hallNumber, int type, int seatsNum, vector<Ticket> &tickets)
{
	for (Seance seance : Seances )
		if ((seance.GetName() == name) && (seance.GetDate() == date) && (seance.GetTime() == time) && (RealTime() > date + time))
		{
			if (seance.GetHall().GetFreePlaces(type) < seatsNum)
				return false;
			for (int i = 0; i < seatsNum; i++)
			{
				Ticket ticket;
				seance.GetHall().BuyTicket(type, ticket.Row, ticket.Col);
				ticket.Date = date;
				ticket.Time = time;
				ticket.HallNumber = hallNumber;
				ticket.Name = name;
				tickets.push_back(ticket);
				if (time < "12_00")
					ticket.Cost = seance.GetHall().GetCost(type) * 0.75;
				else
					if(time > "18_00")
						ticket.Cost = seance.GetHall().GetCost(type) * 1,5;
					else
						ticket.Cost = seance.GetHall().GetCost(type);
			}
			return true;
		}
	return false;
}

bool TicketWindow::ReturnTicket(vector<Ticket>& tickets)
{
	return false;
}
