#pragma once
#include <vector>
using std::vector;

class Hall
{
	struct VIPZone
	{
		int Cost;
		int Rows;
		int Cols;
	};
	struct DefaultZone
	{
		int Cost;
		int Rows;
		int Cols;
	};

	DefaultZone defaultZone;
	VIPZone vipZone;

	int **HallMatrix;
	int FreeDefPlaces;
	int FreeVIPPlaces;
public:
	Hall();
	Hall(int vipCost, int vipRows, int vipCols, int defCost, int defRows, int defCols);
	Hall(const Hall &hall);
	Hall operator=(const Hall &hall);
	void Init();
	~Hall();

	/*
	void SetVIPCost(int cost) { vipZone.Cost = cost; }
	void SetVIPCols(int cols) { vipZone.Cost = cols; }
	void SetVIPRows(int rows) { vipZone.Cost = rows; }
	void SetDefCost(int cost) { vipZone.Cost = cost; }
	void SetDefCols(int cols) { vipZone.Cost = cols; }
	void SetDefRows(int rows) { vipZone.Cost = rows; }
	*/
	
	int GetVIPCols();
	int GetVIPRows();
	int GetCost(int type);
	int GetDefCols();
	int GetDefRows();

	void DecFreePlaces(int type);
	void IncFreePlaces(int type);
	int GetFreePlaces(int type);

	void BuyTicket(int type, int &row, int &seat);
	void ReturnTicket(vector<int> rows, vector<int> cols, int type);
};

