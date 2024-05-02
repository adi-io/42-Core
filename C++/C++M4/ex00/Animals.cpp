#include "Animals.hpp"

Animal&	Animal::operator= (Animal const &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		  this->type = obj.type;
	}
	return (*this);
}

Cat&	Cat::operator= (Cat const &obj)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		  this->type = obj.type;
	}
	return (*this);
}

Dog&	Dog::operator= (Dog const &obj)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		  this->type = obj.type;
	}
	return (*this);
}

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat constructer called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructer called" << std::endl;
}

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog constructer called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructer called" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}

std::string	Cat::getType() const
{
	return (this->type);
}

std::string	Dog::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	std::cout << "Some sound" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow...." << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Bow...." << std::endl;
}
