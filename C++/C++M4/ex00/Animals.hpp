#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class	Animal
{
	protected:
		std::string	type;
	public:
		virtual	std::string	getType() const;
		virtual Animal	&operator= (Animal const &obj);
		virtual	void	makeSound() const;
};

class	Cat : public Animal
{
	public:
		Cat();
		~Cat();
		void	makeSound() const;
		std::string	getType() const;
		Cat	&operator= (Cat const &obj);
};

class	Dog : public Animal
{
	public:
		Dog();
		~Dog();
		void	makeSound() const;
		std::string	getType() const;
		Dog	&operator= (Dog const &obj);
};

#endif
