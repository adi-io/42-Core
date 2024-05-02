#include "PhoneBook.hpp"

void	ft_add(PhoneBook& PhoneBook)
{
	Contact	temp;
	string	str;
	int	num;

	num = 0;
	cout << "Welcome my child" << endl;
	while (1)
	{
		cout << "Please enter the first name: ";
		getline(cin, str);
		if (str[0])
		{
			temp.FirstName = str;
			break;
		}
	}
	while (1)
	{
		cout << "Please enter the last name: ";
		getline(cin, str);
		if (str[0])
		{
			temp.LastName = str;
			break;
		}
	}
	while (1)
	{
		cout << "Please enter the nick name: ";
		getline(cin, str);
		if (str[0])
		{
			temp.NickName = str;
			break;
		}
	}

	while (1)
	{
		cout << "Please enter the phone number: ";
		//TODO impliment a custum IsNum checker;
		getline(cin, str);
		num = std::stoi(str);
		if (num != 0)
		{
			temp.PhoneNumber = num;
			break;
		}
	}
	while (1)
	{
		cout << "Please enter the darkest secret: ";
		getline(cin, str);
		if (str[0])
		{
			temp.DarkestSecret = str;
			break;
		}
	}
	PhoneBook.AddContact(temp);
	cout << "Insertion Successful" << endl;
}

void	putstr(std::string temp)
{
	std::cout << " | ";
	if (temp.size() > 10)
	{
		temp.resize(9);
		std::cout << temp;
		std::cout << ".";
	}
	else
		std::cout << std::setw(10) << temp;
}

void	ft_search(PhoneBook& PhoneBook)
{
	int	i;
	int	j;

	i = 0;
	while (i < PhoneBook.TotalContacts)
	{
		std::cout << std::setw(10) << i + 1;
		putstr(PhoneBook.Contacts[i].FirstName);
		putstr(PhoneBook.Contacts[i].LastName);
		putstr(PhoneBook.Contacts[i].NickName);
		std::cout << "|" << endl;
		i++;
	}
	while (1)
	{
		if (PhoneBook.TotalContacts == 0)
			break ;
		std::cout << "Select ID: ";
		std::cin >> j;
		if (j > 0 && j <= PhoneBook.TotalContacts)
		{
			std::cout << "Phone Number: " << PhoneBook.Contacts[j - 1].PhoneNumber << endl;
			return ;
		}
	}
}

int	main(int argc, char **argv)
{
	PhoneBook PhoneBook;

	while (1)
	{
		string	str;

		cout << "Start by entering ADD, SEARCH, or EXIT" << endl;
		getline (cin, str);
		if (str == "ADD")
			ft_add(PhoneBook);
		else if (str == "SEARCH")
			ft_search(PhoneBook);
		else if (str == "EXIT")
			return (0);
		else
			cout << "Please enter a valid commad" << endl;
	}
}
