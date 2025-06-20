#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{

    Base    *randomy;

    int num = std::rand() % 3;
    if (num == 0)
        randomy = new A;
    else if (num == 1)
        randomy = new B;
    else
        randomy = new C;

    return randomy;
}


void identify(Base* p)
{
    A   *atype = dynamic_cast<A*>(p);

    if (atype)
    {
        std::cout << "The type of the object pointed to by p: A" << std::endl;
        return ;
    }

    B   *btype = dynamic_cast<B*>(p);

    if (btype)
    {
        std::cout << "The type of the object pointed to by p: B" << std::endl; 
        return ;
    }
    
    C   *ctype = dynamic_cast<C*>(p);

    if (ctype)
    {
        std::cout << "The type of the object pointed to by p: C" << std::endl;
        return ;
    }
    
    std::cout << "The type of the object pointed to by p: Base" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A   a = dynamic_cast<A&>(p);
        std::cout << "The type of the object referenced by p: A" << std::endl; 
        return ;

    }
    catch(const std::exception& e)
    {
        try
        {
            B   b = dynamic_cast<B&>(p);
            std::cout << "The type of the object referenced by p: B" << std::endl; 
            return ;
            
        }
        catch(const std::exception& e)
        {
            try
            {
                C   c = dynamic_cast<C&>(p);
                std::cout << "The type of the object referenced by p: C" << std::endl; 
                return ;
            }
            catch(const std::exception& e)
            {
                std::cout << "The type of the object referenced by p: Base" << std::endl; 
                return ;
            }
            

        }
        
    }
    
}