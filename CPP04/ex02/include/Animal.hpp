#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
    std::string type;

public:
    // Orthodox Canonical Form
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

    // Pure virtual function → makes Animal ABSTRACT!
    virtual void makeSound() const = 0;  // ← KEY CHANGE!
    
    // Regular member function (not virtual)
    std::string getType() const;
};

#endif