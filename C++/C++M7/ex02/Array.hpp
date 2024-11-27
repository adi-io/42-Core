#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
public:
    Array();
    Array(unsigned int i);
    Array(const Array<T>& obj);
    ~Array();
    Array<T>& operator=(const Array<T>& obj);
    T& operator[](unsigned int index);
    unsigned int size() const;

private:
    T* n_array;
    unsigned int n_size;
};

#include "Array.tpp"

#endif
