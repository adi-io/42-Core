#include <iostream>
#include <stack>
#include <string>

class	RPN
{
	private:
		std::stack<int> stack;
	public:
		RPN(std::string str);
		RPN(const RPN &var);
		~RPN();
		RPN &operator=(const RPN &var);
};
