#include "AbstractAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::string sep(50, '*');
    unsigned int size = 6;
    const AbstractAnimal *animals[size];
    // AbstractAnimal animal("Animal");//object of abstract class is not allowed

    for (unsigned int i = 0; i < size; i++)
    {
        std::cout << sep << std::endl;
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << sep << std::endl;

    for ( unsigned int i = 0; i < size; i++)
    {
        animals[i]->makeSound();
        delete animals[i];
        std::cout << sep << std::endl;
    }

    return 0;
}
