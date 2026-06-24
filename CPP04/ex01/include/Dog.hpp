#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain* brain; // Pointer to a Brain object

public:
    // Orthodox Canonical Form
    Dog();
    Dog(const Dog& other); // DEEP COPY!
    Dog& operator=(const Dog& other); // DEEP COPY!
    ~Dog();

    // Override
    virtual void makeSound() const;

    // Additional methods to interact with the Brain
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif