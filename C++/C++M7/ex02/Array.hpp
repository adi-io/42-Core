#pragma once

#include <iostream>
#include <string>

template <typename T>

class Array
{
	private:
		T*	n_array;
		unsigned int	n_size;
	public:
		Array();
		Array(unsigned int i);
		Array(const Array& obj);
		~Array;
		Array& operator=(const Array& obj);


