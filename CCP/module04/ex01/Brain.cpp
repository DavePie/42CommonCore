#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain created" << std::endl;
}

Brain::Brain(Brain &other)
{
	for (unsigned long i = 0; i < sizeof(ideas) / sizeof(ideas[0]); i++)
		ideas[i] = other.ideas[i];
	std::cout << "Brain created" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain deleted" << std::endl;
}

Brain &Brain::operator=(Brain &other)
{
	for (unsigned long i = 0; i < sizeof(ideas) / sizeof(ideas[0]); i++)
		ideas[i] = other.ideas[i];
	return *this;
}
