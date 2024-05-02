#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class	Brain
{
	public:
		std::string	ideas[100];
		Brain ();
		~Brain ();
		Brain(const Brain &other);
		Brain	&operator= (const Brain &otherobj);
};

class	Animal
{
	protected:
		std::string	type;
	public:
		virtual ~Animal();
		virtual	std::string	getType() const;
		virtual Animal	&operator= (Animal const &obj);
		virtual	void	makeSound() const = 0;
		virtual Brain	*getBrain(void) const;
};

class	Cat : public Animal
{
	private:
		Brain*	brain;
	public:
		Cat();
		~Cat();
		void	makeSound() const;
		std::string	getType() const;
		Cat	&operator= (Cat const &obj);
		Brain	*getBrain(void) const;
};

class	Dog : public Animal
{
	private:
		Brain*	brain;
	public:
		Dog();
		~Dog();
		void	makeSound() const;
		std::string	getType() const;
		Dog	&operator= (Dog const &obj);
		Brain	*getBrain(void) const;
};

#endif
