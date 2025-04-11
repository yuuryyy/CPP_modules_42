#include "Dog.hpp"

Dog::Dog( void ) : AAnimal("Dog")
{
    std::cout << "Dog default constructor called." << std::endl;
    this->_brain = new Brain();
    for (int i = 0; i < 100; i++)
        this->_brain->setIdea(i, "this person is so kind to me , is he a god.");
}

Dog::Dog( const Dog &dog ) : AAnimal("Dog")
{
    std::cout << "Dog copy constructor called." << std::endl;
    *this = dog;
}

Dog
&Dog::operator=( const Dog &dog )
{
    std::cout << "Dog assignation operator called." << std::endl;

    if (this != &dog)
    {
        if (this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*dog._brain);
        this->type = dog.type;
    }

    return *this;
}

void
Dog::makeSound( void ) const
{
    std::cout << "WOUF WOUF." << std::endl;
}

Dog::~Dog( void )
{
    delete this->_brain;
    this->_brain = NULL;

    std::cout << "Dog destructor called." << std::endl;
}
