#include <iostream>
#include <stack>
#include <string>

int	main(int argc, char *argv[])
{
	std::string str;
	std::stack<int> stack;
	int i;
	int res;
	int num;
	char cur;

	i = 0;
	if (argc == 2)
	{
		str = argv[1];
		while (i < str.size())
		{
			while (i < str.size() && str[i] == ' ')
				i++;

			if (i >= str.size())
				break;

			if (isdigit(str[i]))
				stack.push(str[i] - '0');
			else
			{
				cur = str[i];

				if (stack.size() < 2)
				{
					std::cerr << "Error: Insufficient operands for operation " << cur << std::endl;
					return 1;
				}

				int num2 = stack.top();
				stack.pop();

				int num1 = stack.top();
				stack.pop();

				switch (cur)
				{
					case '+':
						res = num1 + num2;
						break;
					case '-':
						res = num1 - num2;
						break;
					case '/':
						res = num1 / num2;
						break;
					case '*':
						res = num1 * num2;
						break;
					default:
						std::cerr << "Error: Unknown operator " << cur << std::endl;
						return 1;
				}
				stack.push(res);
			}
			i++;
		}
		res = stack.top();
		std::cout << "Result: " << res << std::endl;

	}
	else
		std::cout << "Invalid input" << std::endl;
	return (0);
}
