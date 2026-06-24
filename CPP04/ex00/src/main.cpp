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
    std::cout << "\n========== TESTE 1: Polimorfismo correto ==========\n" << std::endl;
    
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "\nTipos:" << std::endl;
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;

    std::cout << "\nSons:" << std::endl;
    cat->makeSound();  // Deve imprimir "Meow! Meow!"
    dog->makeSound();  // Deve imprimir "Woof! Woof!"
    meta->makeSound(); // Deve imprimir "Animal makes an undefined sound"

    delete meta;
    delete dog;
    delete cat;

    std::cout << "\n========== TESTE 2: Sem polimorfismo (Wrong) ==========\n" << std::endl;
    
    const WrongAnimal* wrong_meta = new WrongAnimal();
    const WrongAnimal* wrong_cat = new WrongCat();

    std::cout << "\nTipos:" << std::endl;
    std::cout << "WrongCat type: " << wrong_cat->getType() << std::endl;

    std::cout << "\nSons:" << std::endl;
    wrong_cat->makeSound();  // Deve imprimir "WrongAnimal makes a wrong sound" (NÃO é o som do gato!)
    wrong_meta->makeSound();

    delete wrong_meta;
    delete wrong_cat;

    std::cout << "\n========== TESTE 3: Teste de cópia ==========\n" << std::endl;
    
    Dog original_dog;
    Dog copy_dog(original_dog);
    
    std::cout << "Original dog type: " << original_dog.getType() << std::endl;
    std::cout << "Copy dog type: " << copy_dog.getType() << std::endl;
    original_dog.makeSound();
    copy_dog.makeSound();

    std::cout << "\n========== TESTE 4: Array de animais ==========\n" << std::endl;
    
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

    std::cout << "\n========== FIM DOS TESTES ==========\n" << std::endl;
    
    return 0;
}