#pragma once

#include <iostream>
#include <string>

template <typename T>
void	iter(T *p, size_t size, void(*f)(T const &))
{
	int 	i;

	i = 0;
	while (i < size)
	{
		f(p[i]);
		i++;
	}
};
