#include <iostream>
#include <string>
#include <fstream>

int	serach_replace(std::string oldfile, std::string str1, std::string str2)
{
	std::string	aux;
	std::string	line;
	std::size_t	last;
	std::size_t	word;

	std::ifstream inFile;
	inFile.open(oldfile.c_str());
	if (inFile.fail())
		return (1);
	std::ofstream outFile((oldfile + ".replace").c_str());
	if (outFile.fail())
		return (1);
	while (getline(inFile, line))
	{
		last = 0;
		while ((word = line.find(str1, last)) != std::string::npos)
		{
			aux = line.substr(word + str1.size()); //capture evything post delta i.e(first letter + str1 len)
			line.erase(word); //erase the from the first instance
			line += str2 + aux;
			last += word + str2.size();
		}
		outFile << line;
		if (!inFile.eof())
			outFile << std::endl;

	}
	inFile.close();
	outFile.close();
	return (0);
}


int	main(void)
{

	std::string	filename;
	std::string	str1;
	std::string	str2;
	std::string	line;

	std::cout << "Please enter the file name: " << std::endl;
	getline(std::cin, filename);
	std::cout << "Please enter the first sentence: " << std::endl;
	getline(std::cin, str1);
	std::cout << "Please enter the second sentence: " << std::endl;
	getline(std::cin, str2);

	serach_replace(filename, str1, str2);

	std::cout << "Opration completed" << std::endl;
	return (0);
}
