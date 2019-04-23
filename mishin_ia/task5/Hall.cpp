#include "Hall.h"

Hall::Hall()
{
}

Hall::Hall(int vipCost, int vipRows, int vipCols, int defCost, int defRows, int defCols) : 
		   vipZone({vipCost, vipRows, vipCols }), defaultZone({ defCost, defRows, defCols })
{
	int **HallMatrix = new int* [defRows];
	for (int i = 0; i < defRows; i++)
	{
		HallMatrix[i] = new int[defCols];
	}
	
	Init();

	FreeVIPPlaces = vipCols * vipRows;
	FreeDefPlaces = defCols * defRows - FreeVIPPlaces;
}

Hall::Hall(const Hall & hall)
{
	vipZone.Cols = hall.vipZone.Cols;
	vipZone.Cols = hall.vipZone.Rows;
	vipZone.Cols = hall.vipZone.Cost;
	defaultZone.Cols = hall.defaultZone.Cols;
	defaultZone.Cols = hall.defaultZone.Rows;
	defaultZone.Cols = hall.defaultZone.Cost;
}

Hall Hall::operator=(const Hall & hall)
{
	vipZone.Cols = hall.vipZone.Cols;
	vipZone.Cols = hall.vipZone.Rows;
	vipZone.Cols = hall.vipZone.Cost;
	defaultZone.Cols = hall.defaultZone.Cols;
	defaultZone.Cols = hall.defaultZone.Rows;
	defaultZone.Cols = hall.defaultZone.Cost;
	return *this;
}

void Hall::Init()
{
	for (int i = 0; i < defaultZone.Rows; i++)
		for (int j = 0; j < defaultZone.Cols; j++)
			if ((i < (defaultZone.Rows / 2 - vipZone.Rows / 2)) || (i > (defaultZone.Rows / 2 + vipZone.Rows / 2))
				|| (j < (defaultZone.Cols / 2 - vipZone.Cols / 2)) || (j > (defaultZone.Cols / 2 + vipZone.Cols / 2)))
				HallMatrix[i][j] = 0;
			else
				HallMatrix[i][j] = 2;
}

Hall::~Hall()
{
	for (int i = 0; i < defaultZone.Rows; i++)
		delete[] HallMatrix[i];
}

int Hall::GetVIPCols() { return vipZone.Cols; }
int Hall::GetVIPRows() { return vipZone.Rows; }
int Hall::GetDefCols() { return defaultZone.Cols; }
int Hall::GetDefRows() { return defaultZone.Rows; }

int Hall::GetCost(int type) 
{ 
	if (type == 0)
		return defaultZone.Cost;
	else
		return vipZone.Cost;
}

void Hall::DecFreePlaces(int type)
{
	if (type == 0)
		FreeDefPlaces--;
	else
		FreeVIPPlaces--;
}

void Hall::IncFreePlaces(int type)
{
	if (type == 0)
		FreeDefPlaces++;
	else
		FreeVIPPlaces++;
}

int Hall::GetFreePlaces(int type)
{
	if (type == 0)
		return FreeDefPlaces;
	else
		return FreeVIPPlaces;
}

void Hall::BuyTicket(int type, int &row, int &seat)
{
	for (int i = 0; i < defaultZone.Rows; i++)
		for (int j = 0; j < defaultZone.Cols; j++)
			if (HallMatrix[i][j] == type)
			{
				HallMatrix[i][j] == 1;
				DecFreePlaces(type);
				row = i;
				seat = j;
				return;
			}
}

void Hall::ReturnTicket(vector<int> rows, vector<int> cols, int type)
{
	for (int i = 0; i < rows.size(); i++)
	{
		HallMatrix[rows[i]][cols[i]] = type;
		IncFreePlaces(type);
	}
}


