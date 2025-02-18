
#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;

    public:

        WrongAnimal( void );
        WrongAnimal( const std::string &type );
        WrongAnimal( const WrongAnimal &wroong );

        WrongAnimal &operator=( const WrongAnimal &WrongAnimal );

        std::string getType( void ) const;

        void makeSound( void ) const;

        virtual ~WrongAnimal( void );
};

#endif
