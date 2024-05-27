#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
void	swap(T &arg1, T &arg2)
{
	T	tmp;

	tmp = arg1;
	arg1 = arg2;
	arg2 = tmp;
};

template <typename T1>

T1	min(T1 i, T1 j)
{
	if (i > j)
		return (j);
	else
		return (i);
};

template <typename T1>

T1	max(T1 i, T1 j)
{
	if (i > j)
		return (i);
	else
		return (j);
};

#endif
