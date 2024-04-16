#include <iostream>
#include <string>

using namespace std;

class	Contact
{
	public:

		int	id;
		string	FirstName;
		string	LastName;
		string	NickName;
		string	PhoneNumber;
		string	DarkestSecret;
};

class PhoneBook
{
	private:
		Contact	Contacts[8];
		int	IndexContacts;
	public:
		PhoneBook() : IndexContacts(0) {}
		void	AddContact(Contact NewContact)
		{
			if (IndexContacts > 8)
			{
				Contacts[0] = NewContact;
				IndexContacts = 1;
				NewContact.id = IndexContacts;
			}
			else
			{
				Contacts[IndexContacts];
				IndexContacts++;
				NewContact.id = IndexContacts;
			}
		}

};


