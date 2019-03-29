#include "ContactsBase.h"
#include <iostream>

int main()
{
	Contact contact1("Fred", "Perry", "John", "909090990");
	ContactsBase base;
	base.AddNewContact(contact1);
	
	if (base.ReadFromFile("Contacts.txt"))
	{
		Contact contact2 = base.ShowContact(1);
		std::cout << contact2;
	}
	system("pause");
}