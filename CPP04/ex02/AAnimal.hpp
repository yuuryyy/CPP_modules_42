#ifndef A_ANIMAL_HPP
#define A_ANIMAL_HPP

#include <iostream>

class AAnimal
{
    protected:
        std::string type;

    public:

        AAnimal( void );
        AAnimal( const std::string &type );
        AAnimal( const AAnimal &animal );

        AAnimal &operator=( const AAnimal &animal );

        std::string getType( void ) const;

        virtual void makeSound( void ) const = 0;

        virtual ~AAnimal( void );
};

#endif
