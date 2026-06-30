#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

// The main objective of Exercise 00 is to understand and implement subtype
// polymorphism in C++ using virtual functions.

// - Understand Virtual Functions
// - Implement Inheritance Hierarchy
// - Demonstrate Polymorphic Behavior

int main()
{
    std::cout << "\n========== TEST 1: Polymorphism working ==========\n" << std::endl;

    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "\nTypes:" << std::endl;
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;

    std::cout << "\nSounds:" << std::endl;
    cat->makeSound();  // Prints "Meow! Meow!"
    dog->makeSound();  // Prints "Woof! Woof!"
    meta->makeSound(); // Prints "Animal makes an undefined sound"

    delete meta;
    delete dog;
    delete cat;

    // once there is no virtual function, the base class function is called 
    // instead of the derived class function
    std::cout << "\n========== TEST 2: Without Polymorphism (Wrong) ==========\n" << std::endl;

    const WrongAnimal* wrong_meta = new WrongAnimal();
    const WrongAnimal* wrong_cat = new WrongCat();

    std::cout << "\nTypes:" << std::endl;
    std::cout << "WrongCat type: " << wrong_cat->getType() << std::endl;

    std::cout << "\nSounds:" << std::endl;
    wrong_cat->makeSound();  // Prints "WrongAnimal makes a wrong sound" (This is not the cat's sound!)
    wrong_meta->makeSound();

    delete wrong_meta;
    delete wrong_cat;

    std::cout << "\n========== TEST 3: Copy Test ==========\n" << std::endl;

    Dog original_dog;
    Dog copy_dog(original_dog);

    std::cout << "Original dog type: " << original_dog.getType() << std::endl;
    std::cout << "Copy dog type: " << copy_dog.getType() << std::endl;
    original_dog.makeSound();
    copy_dog.makeSound();

    std::cout << "\n========== TEST 4: Array of Animals ==========\n" << std::endl;

    Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

    for (int i = 0; i < 4; i++)
    {
        std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }

    for (int i = 0; i < 4; i++)
        delete animals[i];

    std::cout << "\n========== END OF TESTS ==========\n" << std::endl;

    return 0;
}