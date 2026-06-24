#include "../include/Cat.hpp"

// Default constructor
Cat::Cat()
{
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain(); // Allocate memory for the brain
}

// Copy constructor
Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain); // DEEP COPY!
}

// Assignment operator
Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        // Delete the existing brain and create a new one
        delete this->brain;
        this->brain = new Brain(*other.brain); // DEEP COPY!
    }
    return *this;
}

// Destructor
Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain; // Free the memory allocated for the brain
}

// Override makeSound
void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}

// Set an idea in the cat's brain
void Cat::setIdea(int index, const std::string& idea)
{
    if (brain)
        brain->setIdea(index, idea);
}

// Get an idea from the cat's brain
std::string Cat::getIdea(int index) const
{
    if (brain)
        return brain->getIdea(index);
    return "";
}