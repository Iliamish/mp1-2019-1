#pragma once



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
public:
	Hall(int cost);
	~Hall();
};

