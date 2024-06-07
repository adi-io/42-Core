#include "RPN.hpp"

RPN::RPN(std::string str)
{
	int i;
	int res;
	int num;
	char cur;

	i = 0;
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
				exit (1);
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
					exit (1);
			}
			stack.push(res);
		}
		i++;
	}
	res = stack.top();
	std::cout << "Result: " << res << std::endl;

}

RPN::~RPN() {}
