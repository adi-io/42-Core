#include "Span.hpp"

Span::Span()
{
	size = 0;
}

Span::Span(int	i)
{
	size = i;
}

void	Span::addNumber(int num)
{
	if (numbers.size() == size)
		throw std::out_of_range("Span is full");
	numbers.push_back(num);
}

int	Span::shortestSpan()
{
	int	shortest;
	if (numbers.size() < 2)
		throw std::runtime_error("Too few elements in the Span");
	std::sort(numbers.begin(), numbers.end());
	shortest = numbers[1] - numbers[0];
	for (int i = 2; i < numbers.size(); i++)
	{
		shortest = std::min(shortest, numbers[i] - numbers[i-1]);
	}
	return (shortest);
}

int	Span::longestSpan()
{
	int	i;
	int	j;

	if (numbers.size()< 2)
		throw std::runtime_error("Too few elements in the Span");
	i = *std::max_element(numbers.begin(), numbers.end());
	j = *std::min_element(numbers.begin(), numbers.end());
	return (i - j);
}
