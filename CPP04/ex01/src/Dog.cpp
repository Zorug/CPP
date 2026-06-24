#include "../include/Dog.hpp"

// Default constructor - make a brain for the dog
Dog::Dog()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain(); // Allocate memory for the brain
}

// Copy constructor
Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    // Make a new Brain and copy the ideas from the other dog's brain
    this->brain = new Brain(*other.brain); // DEEP COPY!
}

// Assignment operator
Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        // Delete the existing brain and create a new one
        delete this->brain;
        this->brain = new Brain(*other.brain); // DEEP COPY!
    }
    return *this;
}

// Destructor
Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain; // Free the memory allocated for the brain
}

// Override makeSound
void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}

// Set an idea in the dog's brain
void Dog::setIdea(int index, const std::string& idea)
{
    if (brain)
        brain->setIdea(index, idea);
}

// Get an idea from the dog's brain
std::string Dog::getIdea(int index) const
{
    if (brain)
        return brain->getIdea(index);
    return "";
}