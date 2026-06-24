#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain* brain; // Pointer to a Brain object

public:
    // Orthodox Canonical Form
    Cat();
    Cat(const Cat& other); // DEEP COPY!
    Cat& operator=(const Cat& other); // DEEP COPY!
    ~Cat();

    // Override
    virtual void makeSound() const;

    // Additional methods to interact with the Brain
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif