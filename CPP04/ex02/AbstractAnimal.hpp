#ifndef ABSTRACT_ANIMAL_HPP
#define ABSTRACT_ANIMAL_HPP

#include <iostream>

class AbstractAnimal
{
    protected:
        std::string type;

    public:

        AbstractAnimal( void );
        AbstractAnimal( const std::string &type );
        AbstractAnimal( const AbstractAnimal &animal );

        AbstractAnimal &operator=( const AbstractAnimal &animal );

        std::string getType( void ) const;

        virtual void makeSound( void ) const = 0;

        virtual ~AbstractAnimal( void );
};

#endif
