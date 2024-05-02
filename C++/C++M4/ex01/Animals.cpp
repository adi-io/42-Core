#include "Animals.hpp"

Brain::Brain()
{
	std::cout << "Brain constructer called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructer called" << std::endl;
}

Brain*	Animal::getBrain(void) const
{
	return (NULL);
}

Brain*	Cat::getBrain(void) const
{
	return (this->brain);
}

Brain*	Dog::getBrain(void) const
{
	return (this->brain);
}

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
	(this->brain) = (obj.brain);
	return (*this);
}

Dog&	Dog::operator= (Dog const &obj)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		  this->type = obj.type;
	}
	(this->brain) = (obj.brain);
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Base destructer called" << std::endl;
}

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat constructer called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructer called" << std::endl;
	delete this->brain;
}

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog constructer called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructer called" << std::endl;
	delete this->brain;
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
