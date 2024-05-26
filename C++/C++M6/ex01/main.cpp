#include "Serializer.hpp"

int	main(void)
{
	Data	odata;

	odata.n = 42;
	uintptr_t sdata = Serializer::serialize(&odata);
	Data*	ddata = Serializer::deserialize(sdata);;
	if (ddata == &odata)
	{
		std::cout << "Orignal Data value: " << odata.n << std::endl;
		std::cout << "Deserialized Data value: " << ddata -> n << std::endl;
	}
	else
		std::cout << "Serialization & Deserialization failed"<< std::endl;
	return (0);

}

