#include "TicketWindow.h"
#include <iostream>

using std::cout;


int main() {
	TicketWindow ticketWindow;
	vector<Ticket> tickets;
	ticketWindow.BuyTicket("2019_05_29", "12_00", "Titanic", 2, 0, 1, tickets);
	system("pause");
}