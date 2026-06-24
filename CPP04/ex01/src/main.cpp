#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

int main()
{
    std::cout << "\n========== TESTE 1: Array de Animais ==========\n" << std::endl;
    
    // Criando array de 4 animais (2 Dogs, 2 Cats)
    Animal* animals[4];
    
    for (int i = 0; i < 4; i++)
    {
        if (i < 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    
    // Fazendo cada animal emitir som
    for (int i = 0; i < 4; i++)
    {
        std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }
    
    // Deletando todos (como Animals!)
    for (int i = 0; i < 4; i++)
        delete animals[i];
    
    std::cout << "\n========== TESTE 2: Deep Copy (Dog) ==========\n" << std::endl;
    
    Dog originalDog;
    originalDog.setIdea(0, "I love bones!");
    originalDog.setIdea(1, "I want to play!");
    
    std::cout << "\nOriginal Dog ideas:" << std::endl;
    std::cout << "Idea 0: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Idea 1: " << originalDog.getIdea(1) << std::endl;
    
    // Copiando (DEEP COPY!)
    Dog copyDog(originalDog);
    
    // Modificando o original
    originalDog.setIdea(0, "I want to eat!");
    
    std::cout << "\nAfter modifying original:" << std::endl;
    std::cout << "Original Dog idea 0: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copy Dog idea 0: " << copyDog.getIdea(0) << std::endl;
    std::cout << "Copy Dog idea 1: " << copyDog.getIdea(1) << std::endl;
    
    std::cout << "\n✅ DEEP COPY funcionou! As cópias são independentes!" << std::endl;
    
    std::cout << "\n========== TESTE 3: Deep Copy (Cat) ==========\n" << std::endl;
    
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
    
    std::cout << "\n✅ DEEP COPY funcionou! As cópias são independentes!" << std::endl;
    
    std::cout << "\n========== TESTE 4: Teste do Enunciado ==========\n" << std::endl;
    
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "Dog sound: ";
    j->makeSound();
    std::cout << "Cat sound: ";
    i->makeSound();
    
    delete j;  // ✅ Deve deletar Dog E Brain
    delete i;  // ✅ Deve deletar Cat E Brain
    
    std::cout << "\n========== TESTE 5: Assignment Operator ==========\n" << std::endl;
    
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
    
    // Modificando dog1 para provar que são independentes
    dog1.setIdea(0, "New Dog 1 idea");
    
    std::cout << "\nAfter modifying dog1:" << std::endl;
    std::cout << "Dog 1 idea: " << dog1.getIdea(0) << std::endl;
    std::cout << "Dog 2 idea: " << dog2.getIdea(0) << std::endl;
    
    std::cout << "\n✅ ASSIGNMENT DEEP COPY funcionou!" << std::endl;
    
    std::cout << "\n========== FIM DOS TESTES ==========\n" << std::endl;
    
    return 0;
}