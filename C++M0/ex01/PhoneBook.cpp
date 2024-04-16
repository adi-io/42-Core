#include "PhoneBook.hpp"

void	ft_add(void)
{
	Contact	temp;
	string	str;

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
		cout << "Please enter the phone number: ";
		getline(cin, str);
		if (str[0])
		{
			temp.PhoneNumber = str;
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
}
void	ft_search(void)
{

}

int	main(int argc, char **argv)
{
	while (1)
	{
		string	str;

		cout << "Start by entering ADD, SERACH, or EXIT" << endl;
		getline (cin, str);
		if (str == "ADD")
			ft_add();
		else if (str == "SERACH")
			ft_search();
		else if (str == "EXIT")
			return (0);
		else
			cout << "Please enter a valid commad" << endl;
	}
}
