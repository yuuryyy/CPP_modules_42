#include <sstream>
#include <iostream>
#include <cstdio>
#include <limits>
#include "ScalarConverter.hpp"


int main(int ac, char **av)
{
    if (ac != 2)
        return 1;
    std::string data(av[1]);
    ScalarConverter::convert(data);

}