#ifndef SERIALIZER_HPP__
#define SERIALIZER_HPP__

#include <iostream>
#include <string>
#include <cstdio>
#include <stdint.h>
  
#include "Data.hpp"

class Serializer
{

        Serializer( void );
        Serializer(const Serializer& Other);
        Serializer& operator=(const Serializer& Other);
        ~Serializer( void );
    
    public:

        static uintptr_t    serialize(Data* ptr); 
        static Data*        deserialize(uintptr_t raw);


};


#endif