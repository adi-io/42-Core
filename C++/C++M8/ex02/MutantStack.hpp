#pragma once

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T>>
{
	public:
		typedef typename std::stack<T, std::deque<T>>::container_type::iterator iterator;

		MutantStack() {};
		iterator begin()
		{
			return this->c.begin();
		}
		iterator end()
		{
			return this->c.end();
		}
};
