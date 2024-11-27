#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <cstdint>
#include <stdint.h>

struct	Data
{
	int	n;
};

class	Serializer
{
	public:
		static uintptr_t serialize(Data* ptr)
		{
			return (reinterpret_cast<uintptr_t> (ptr));
		}
		static Data* deserialize(uintptr_t raw)
		{
			return (reinterpret_cast<Data*> (raw));
		}
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
};

#endif
