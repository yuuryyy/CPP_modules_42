#include "Cat.hpp"

Cat::Cat( void ) : AbstractAnimal("Cat")
{
    std::cout << "Cat default constructor called." << std::endl;
    this->_brain = new Brain();
    for (int i = 0; i < 100; i++)
        this->_brain->setIdea(i, "this person is so kind to me , am I a god.");
}

Cat::Cat( const Cat &cat ) : AbstractAnimal("Cat")
{
    std::cout << "Cat copy constructor called." << std::endl;
    *this = cat;
}

Cat
&Cat::operator=( const Cat &cat )
{
    std::cout << "Cat assignation operator called." << std::endl;

    if (this != &cat)
    {
        if (this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*cat._brain);
        this->type = cat.type;
    }

    return *this;
}

void
Cat::makeSound( void ) const
{
    std::cout << "WII WII WII." << std::endl;
}

Cat::~Cat( void )
{
    delete this->_brain;
    this->_brain = NULL;

    std::cout << "Cat destructor called." << std::endl;
}
