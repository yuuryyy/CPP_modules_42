#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    Base    *b = generate();

    identify(b);
    identify(*b);


    Base    bb;

    identify(bb);
    identify(&bb);

    Base    *a = generate();

    identify(a);
    identify(*a);

    delete b;
}