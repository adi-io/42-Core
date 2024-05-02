#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class	Contact
{
	public:

		int	Id;
		string	FirstName;
		string	LastName;
		string	NickName;
		int	PhoneNumber;
		string	DarkestSecret;
};

class PhoneBook
{
	public:
		Contact	Contacts[8];
		int	IndexContacts;
		int	TotalContacts;
	public:
		PhoneBook() : IndexContacts(0), TotalContacts(0) {}
		void	AddContact(Contact NewContact)
		{
			if (IndexContacts >= 8)
			{
				Contacts[0] = NewContact;
				IndexContacts = 1;
				NewContact.Id = IndexContacts;
			}
			else
			{
				Contacts[IndexContacts] = NewContact;
				IndexContacts++;
				NewContact.Id = IndexContacts;
				cout << "ID ->" << NewContact.Id << endl;
				if (TotalContacts < 9)
					TotalContacts++;
			}
		}

};


