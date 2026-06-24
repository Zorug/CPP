#include "Brain.hpp"

// Default constructor
Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
}

// Copy constructor - DEEP COPY!
Brain::Brain(const Brain& other) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];	// Copy each idea from
}											// the other Brain object

// Assignment operator - DEEP COPY!
Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i]; // Copy each idea
	}
	return *this;
}

// Destructor
Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

// Method to set an idea at a specific index
void Brain::setIdea(int index, const std::string& idea) {
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100)
		return ideas[index];
	return "";
}
