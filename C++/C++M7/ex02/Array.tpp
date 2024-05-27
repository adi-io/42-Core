#include "Array.hpp"

template <typename T>
Array::Array()
{
	n_size = 0;
	n_array = new T[0];
};

template <typename T>
Array::Array(unsigned int i)
{
	n_size = i;
	n_array = new T[i];
}

template <typename T>
Array::Array(Array& obj)
{
	n_array = new T[obj.size()];
	n_size = obj.size();
	for (unsigned int i = 0, i < n_size , i++)
		n_array[i] = obj[i];
}

Array::~Array()
{
	delete[] n_array;
}

template <typename T>
Array& operator=(Array& obj)
{
	delete[] n_array;
	n_array = new T[obj.size()];
	n_size = obj.size();
	for (unsigned int i = 0, i < n_size , i++)
		n_array[i] = obj[i];
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= n_size)
		throw std::out_of_range("Out of bounds");
	return (n_array[index]);
}

template <typename T>
unsigned int Array<T>::size()
{
	return (n_size);
}
