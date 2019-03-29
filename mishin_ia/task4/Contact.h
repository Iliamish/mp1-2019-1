#pragma once
#include <iostream>
#include <string>

using std::string;

class Contact
{
	string FirstName;
	string SecondName;
	string ThirdName;
	string Day;
	string Month;
	string Year;
	string Tel;
	bool Favourite;
public:
	Contact(string firstName = " ",
	string secondName = " ",
	string thirdName = " ",
	string day = " ",
	string month = " ",
	string year = " ",
	string tel = " ",
	bool favourite = 0);
	Contact(const Contact & cont);
	~Contact();

	Contact operator=(const Contact& cont);

	void SetFirstName(string firstname);
	void SetSecondName(string secondname);
	void SetThirdName(std::string thirdname);
	void SetTel(string tel);
	void SetFavourite(bool fav);
	void SetDay(string day);
	void SetMonth(string month);
	void SetYear(string year);

	string GetFirstName();
	string GetSecondName();
	string GetThirdName();
	string GetTel();
	bool GetFavourite();
	string GetDay();
	string GetMonth();
	string GetYear();
};

