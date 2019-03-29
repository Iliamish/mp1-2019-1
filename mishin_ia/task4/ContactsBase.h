#pragma once
#include "Contact.h"
#include <vector>
#include <iostream>

using std::vector;

class ContactsBase 
{
	vector<Contact> Contacts;
public:
	ContactsBase();
	~ContactsBase();
	
	void AddNewContact(Contact cont);
	void EditChosenContact(Contact cont, int num);
	int FindContactByFIO(string fio);
	int FindContactByTel(string tel);
	vector<Contact> ShowContactsFirstLetter(char letter);
	int NumberOfContacts();
	void SetFavourite(int num);
	void UnsetFavourite(int num);
	vector<Contact> ShowFavContacts(char letter);
	void DeleteContact(int num);
	bool SaveToFile(string path);
	bool ReadFromFile(string path);
	Contact ShowContact(int num);

	friend std::ostream& operator<<(std::ostream &out, Contact &cont);
};

