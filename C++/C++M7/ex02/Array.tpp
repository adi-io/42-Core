#include "Array.hpp"
#include <stdexcept>

template <typename T>
Array<T>::Array()
{
    n_size = 0;
    n_array = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int i)
{
    n_size = i;
    n_array = new T[i];
}

template <typename T>
Array<T>::Array(const Array<T>& obj)
{
    n_size = obj.size();
    n_array = new T[n_size];
    for (unsigned int i = 0; i < n_size; i++)
        n_array[i] = obj.n_array[i];
}

template <typename T>
Array<T>::~Array()
{
    delete[] n_array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& obj)
{
    if (this != &obj)
    {
        delete[] n_array;
        n_size = obj.size();
        n_array = new T[n_size];
        for (unsigned int i = 0; i < n_size; i++)
            n_array[i] = obj.n_array[i];
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= n_size)
        throw std::out_of_range("Out of bounds");
    return n_array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return n_size;
}

