#include "ContactsBase.h"
#include <fstream>

ContactsBase::ContactsBase()
{
}


ContactsBase::~ContactsBase()
{
}

void ContactsBase::AddNewContact(Contact cont)
{
	Contacts.push_back(cont);
}

void ContactsBase::EditChosenContact(Contact cont, int num)
{
	Contacts[num] = cont;
}

int ContactsBase::FindContactByFIO(string fio)
{
	bool flag = false;
	int i = -1;
	for (Contact cont : Contacts)
	{
		i++;
		string str = cont.GetFirstName() + cont.GetSecondName() + cont.GetThirdName();
		if (str == fio)
		{
			flag = true;
			break;
		}
	}
	if (flag)
		return i;
	else
		return -1;
}

int ContactsBase::FindContactByTel(string tel)
{
	bool flag = false;
	int i = -1;
	for (Contact cont : Contacts)
	{
		i++;
		string str = cont.GetTel();
		if (str == tel)
		{
			flag = true;
			break;
		}
	}
	if (flag)
		return i;
	else
		return -1;
}

vector<Contact> ContactsBase::ShowContactsFirstLetter(char letter)
{
	vector<Contact> vec;
	for (Contact cont : Contacts)
		if (cont.GetFirstName()[0] == letter)
			vec.push_back(cont);
	return vec;
}

int ContactsBase::NumberOfContacts()
{
	return Contacts.size();
}

void ContactsBase::SetFavourite(int num)
{
	Contacts[num].SetFavourite(true);
}

void ContactsBase::UnsetFavourite(int num)
{
	Contacts[num].SetFavourite(false);
}

vector<Contact> ContactsBase::ShowFavContacts(char letter)
{
	vector<Contact> vec;
	for (Contact cont : Contacts)
		if (cont.GetFavourite())
			vec.push_back(cont);
	return vec;
}

void ContactsBase::DeleteContact(int num)
{
	Contacts.erase(Contacts.begin() + num);
}

bool ContactsBase::SaveToFile(string path)
{
	std::ofstream fout(path);
	string buff;
	for (Contact cont : Contacts)
	{
		fout << cont.GetFirstName() << std::endl;
		fout << cont.GetSecondName() << std::endl;
		fout << cont.GetThirdName() << std::endl;
		fout << cont.GetTel() << std::endl;
		fout << cont.GetFavourite() << std::endl;
		fout << cont.GetDay() << std::endl;
		fout << cont.GetMonth() << std::endl;
		fout << cont.GetYear() << std::endl;
	}
	fout.close();
	return true;
}

bool ContactsBase::ReadFromFile(string path)
{
	string buff;
	bool fav;
	std::ifstream fin(path);
	if (!fin.is_open())
		return false;
	while(!fin.eof())
	{
		Contact cont;
		fin >> buff;
		cont.SetFirstName(buff);
		fin >> buff;
		cont.SetSecondName(buff);
		fin >> buff;
		cont.SetThirdName(buff);
		fin >> buff;
		cont.SetTel(buff);
		fin >> fav;
		cont.SetFavourite(fav);
		fin >> buff;
		cont.SetDay(buff);
		fin >> buff;
		cont.SetMonth(buff);
		fin >> buff;
		cont.SetYear(buff);
		AddNewContact(cont);
	}
	fin.close();
	return true;
}

Contact ContactsBase::ShowContact(int num)
{
	return Contacts[num];
}

std::ostream & operator<<(std::ostream & out, Contact & cont)
{
	out << cont.GetFirstName() << " " << cont.GetSecondName() << " " << cont.GetThirdName() << " " << cont.GetTel();
	return out;
}
