#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string type;

    public:

        Animal( void );
        Animal( const std::string &type );
        Animal( const Animal &animal );

        Animal &operator=( const Animal &animal );

        std::string getType( void ) const;

        virtual void makeSound( void ) const;

        virtual ~Animal( void );
};

#endif
