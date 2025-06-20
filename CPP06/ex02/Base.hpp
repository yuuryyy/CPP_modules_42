#ifndef BASE_HPP__
#define BASE_HPP__

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

class Base 
{
    public :
        virtual ~Base( void );
};


Base    *generate(void);
void    identify(Base* p);
void    identify(Base& p);

#endif