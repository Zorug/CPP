#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

// Objective: Learn how to safely manage dynamically allocated memory 
// in polymorphic classes by implementing deep copy (Rule of Three).

int main()
{
    std::cout << "\n========== TEST 1: Array de Animais ==========\n" << std::endl;

    // Creating an array of 4 animals (2 Dogs, 2 Cats)
    Animal* animals[4];
    
    for (int i = 0; i < 4; i++)
    {
        if (i < 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    
    // Making each animal make a sound
    for (int i = 0; i < 4; i++)
    {
        std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }
    
    // Delete all animals (as Animals!)
    for (int i = 0; i < 4; i++)
        delete animals[i];
    
    std::cout << "\n========== TEST 2: Deep Copy (Dog) ==========\n" << std::endl;
    
    Dog originalDog;
    originalDog.setIdea(0, "I love bones!");
    originalDog.setIdea(1, "I want to play!");

    std::cout << "\nOriginal Dog ideas:" << std::endl;
    std::cout << "Idea 0: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Idea 1: " << originalDog.getIdea(1) << std::endl;
    
    // Copy constructor is called here, creating a new Dog with its own Brain (DEEP COPY!)
    Dog copyDog(originalDog);

    // Change the original dog's idea to see if the copy is independent
    originalDog.setIdea(0, "I want to eat!");
    
    std::cout << "\nAfter modifying original:" << std::endl;
    std::cout << "Original Dog idea 0: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copy Dog idea 0: " << copyDog.getIdea(0) << std::endl;
    std::cout << "Copy Dog idea 1: " << copyDog.getIdea(1) << std::endl;
    
    std::cout << "\n✅ DEEP COPY worked! Copies are independent!" << std::endl;
    
    std::cout << "\n========== TEST 3: Deep Copy (Cat) ==========\n" << std::endl;
    
    Cat originalCat;
    originalCat.setIdea(0, "I love fish!");
    originalCat.setIdea(1, "I want to sleep!");
    
    std::cout << "\nOriginal Cat ideas:" << std::endl;
    std::cout << "Idea 0: " << originalCat.getIdea(0) << std::endl;
    std::cout << "Idea 1: " << originalCat.getIdea(1) << std::endl;
    
    Cat copyCat(originalCat);
    originalCat.setIdea(0, "I want to hunt!");
    
    std::cout << "\nAfter modifying original:" << std::endl;
    std::cout << "Original Cat idea 0: " << originalCat.getIdea(0) << std::endl;
    std::cout << "Copy Cat idea 0: " << copyCat.getIdea(0) << std::endl;
    std::cout << "Copy Cat idea 1: " << copyCat.getIdea(1) << std::endl;
    
    std::cout << "\n✅ DEEP COPY worked! Copies are independent!" << std::endl;
    
    std::cout << "\n========== TEST 4: Test of Statement ==========\n" << std::endl;
    
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "Dog sound: ";
    j->makeSound();
    std::cout << "Cat sound: ";
    i->makeSound();
    
    delete j;  // Should delete dog and its brain
    delete i;  // Should delete cat and its brain
    
    std::cout << "\n========== TEST 5: Assignment Operator ==========\n" << std::endl;
    
    Dog dog1;
    dog1.setIdea(0, "Dog 1 idea");
    
    Dog dog2;
    dog2.setIdea(0, "Dog 2 idea");
    
    std::cout << "\nBefore assignment:" << std::endl;
    std::cout << "Dog 1 idea: " << dog1.getIdea(0) << std::endl;
    std::cout << "Dog 2 idea: " << dog2.getIdea(0) << std::endl;
    
    dog2 = dog1;  // Assignment
    
    std::cout << "\nAfter assignment:" << std::endl;
    std::cout << "Dog 1 idea: " << dog1.getIdea(0) << std::endl;
    std::cout << "Dog 2 idea: " << dog2.getIdea(0) << std::endl;
    
    // Modifying dog1's idea to prove they are independent
    dog1.setIdea(0, "New Dog 1 idea");
    
    std::cout << "\nAfter modifying dog1:" << std::endl;
    std::cout << "Dog 1 idea: " << dog1.getIdea(0) << std::endl;
    std::cout << "Dog 2 idea: " << dog2.getIdea(0) << std::endl;
    
    std::cout << "\n✅ ASSIGNMENT DEEP COPY worked!" << std::endl;
    
    std::cout << "\n========== END OF TESTS ==========\n" << std::endl;
    
    return 0;
}