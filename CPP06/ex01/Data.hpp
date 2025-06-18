#ifndef DATA_HPP__
#define DATA_HPP__


#include <string>
#include <iostream>

struct Data
{
    unsigned int     id;
    std::string      name;

    Data(unsigned int i, std::string n);
};


#endif