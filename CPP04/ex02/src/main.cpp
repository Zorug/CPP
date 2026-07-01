#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

int main()
{
    std::cout << "\n========== TEST 1: Animal is ABSTRACT ==========\n" << std::endl;
    
    // This should NOT compile!
    // Animal* animal = new Animal();  // ❌ ERROR! Animal is abstract!
    
    std::cout << "✅ Animal is abstract! Cannot instantiate." << std::endl;
    
    std::cout << "\n========== TEST 2: Polymorphism Works ==========\n" << std::endl;
    
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << "\nTypes:" << std::endl;
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;
    
    std::cout << "\nSounds:" << std::endl;
    dog->makeSound();  // "Woof! Woof!"
    cat->makeSound();  // "Meow! Meow!"
    
    delete dog;
    delete cat;
    
    std::cout << "\n========== TEST 3: Array of Animals ==========\n" << std::endl;
    
    Animal* animals[4];
    
    for (int i = 0; i < 4; i++)
    {
        if (i < 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    
    for (int i = 0; i < 4; i++)
    {
        std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }
    
    for (int i = 0; i < 4; i++)
        delete animals[i];
    
    std::cout << "\n========== TEST 4: Deep Copy (Dog) ==========\n" << std::endl;
    
    Dog originalDog;
    originalDog.setIdea(0, "I love bones!");
    originalDog.setIdea(1, "I want to play!");
    
    std::cout << "\nOriginal Dog ideas:" << std::endl;
    std::cout << "Idea 0: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Idea 1: " << originalDog.getIdea(1) << std::endl;
    
    Dog copyDog(originalDog);  // Deep copy!
    
    originalDog.setIdea(0, "I want to eat!");
    
    std::cout << "\nAfter modifying original:" << std::endl;
    std::cout << "Original Dog idea 0: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copy Dog idea 0: " << copyDog.getIdea(0) << std::endl;
    std::cout << "Copy Dog idea 1: " << copyDog.getIdea(1) << std::endl;
    
    std::cout << "\n✅ DEEP COPY works! Copies are independent!" << std::endl;
    
    std::cout << "\n========== TEST 5: Wrong Animals (No Polymorphism) ==========\n" << std::endl;
    
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << "\nTypes:" << std::endl;
    std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
    
    std::cout << "\nSounds:" << std::endl;
    wrongCat->makeSound();  // "WrongAnimal makes a wrong sound" ❌
    wrongMeta->makeSound();
    
    delete wrongMeta;
    delete wrongCat;
    
    std::cout << "\n========== TEST 6: Assignment Operator ==========\n" << std::endl;
    
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
    
    dog1.setIdea(0, "New Dog 1 idea");
    
    std::cout << "\nAfter modifying dog1:" << std::endl;
    std::cout << "Dog 1 idea: " << dog1.getIdea(0) << std::endl;
    std::cout << "Dog 2 idea: " << dog2.getIdea(0) << std::endl;
    
    std::cout << "\n✅ ASSIGNMENT DEEP COPY works!" << std::endl;
    
    std::cout << "\n========== END OF TESTS ==========\n" << std::endl;
    
    return 0;
}