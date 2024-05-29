#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>

class	Span
{
	private:
		std::vector<int> numbers;
		unsigned int	size;
	public:
		Span();
		Span(int n);
		void	addNumber(int num);
		int	shortestSpan();
		int	longestSpan();
};
