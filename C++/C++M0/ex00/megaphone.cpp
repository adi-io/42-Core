#include <iostream>
#include <string>

using namespace std;

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (argc != 1)
	{
		while (j < argc)
		{
			while (argv[j][i])
			{
				if (argv[j][i] >= 'a' && argv[j][i] <= 'z')
					argv[j][i] -= 32;
				cout << argv[j][i];
				i++;
			}
			j += 1;
			i = 0;
		}
		cout << endl;
	}
	else
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
	return (0);
}
