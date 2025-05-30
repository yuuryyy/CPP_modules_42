#include <sstream>
#include <iostream>
#include <cstdio>
#include <limits.h>


int main(int ac, char **av)
{
    std::stringstream str(av[1]);
    float i;

    if (!(str >> i))
        std::cout << "wtf";
    else
        std::cout << i;
    if (str.get() != EOF)
        std::cout << "hihi";
    if (static_cast<float>(i) == static_cast<int>(i))   std::cout << ".0f";

    std::cout << std::endl;

}