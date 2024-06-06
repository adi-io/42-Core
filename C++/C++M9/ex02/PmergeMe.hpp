#pragma once
#include <iostream>
#include <string>
#include <deque>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>

class	PmergeMe
{
	public:
		PmergeMe(int ac, char **av);
		template <typename T>
		void	display (T& container);
		void	MergeSortDeque(std::deque<int> &arr);
		void	MergeSortList(std::list<int> &arr);
};
