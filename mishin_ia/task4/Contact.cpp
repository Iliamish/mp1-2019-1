#include "Contact.h"



Contact::Contact(string firstName, string secondName, string thirdName, string day,
				 string month, string year, string tel, bool favourite):
				 FirstName(firstName), SecondName(secondName), ThirdName(thirdName),
				 Day(day), Month(month), Year(year), Tel(tel), Favourite(favourite)
{

}

Contact::Contact(const Contact & cont)
{
	FirstName = cont.FirstName;
	SecondName = cont.SecondName;
	ThirdName = cont.ThirdName;
	Day = cont.Day;
	Month = cont.Month;
	Year = cont.Year;
	Tel = cont.Tel;
	Favourite = cont.Favourite;
}

Contact::~Contact()
{
}

Contact Contact::operator=(const Contact & cont)
{
	FirstName = cont.FirstName;
	SecondName = cont.SecondName;
	ThirdName = cont.ThirdName;
	Day = cont.Day;
	Month = cont.Month;
	Year = cont.Year;
	Tel = cont.Tel;
	Favourite = cont.Favourite;
	return *this;
}

void Contact::SetFirstName(string firstname)
{
	FirstName = firstname;
}

void Contact::SetSecondName(string secondname)
{
	SecondName = secondname;
}

void Contact::SetThirdName(string thirdname)
{
	ThirdName = thirdname;
}

void Contact::SetTel(string tel)
{
	Tel = tel;
}

void Contact::SetFavourite(bool fav)
{
	Favourite = fav;
}

void Contact::SetDay(string day)
{
	Day = day;
}

void Contact::SetMonth(string month)
{ 
	Month = month;
}

void Contact::SetYear(string year)
{
	Year = year;
}

std::string Contact::GetFirstName()
{
	return FirstName;
}

std::string Contact::GetSecondName()
{
	return SecondName;
}

std::string Contact::GetThirdName()
{
	return ThirdName;
}

std::string Contact::GetTel()
{
	return Tel;
}

bool  Contact::GetFavourite()
{
	return Favourite;
}

std::string Contact::GetDay()
{
	return Day;
}

std::string Contact::GetMonth()
{
	return Month;
}

std::string Contact::GetYear()
{
	return Year;
}
