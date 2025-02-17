#include "DiamondTrap.hpp"

int main( void )
{

    std::string separator(70, '*');

    DiamondTrap diamond1("DI4M-TP");
    DiamondTrap diamond2(diamond1);
    DiamondTrap diamond3("LSEM-TP");

    std::cout << separator << "\n" << std::endl;
    diamond3.whoAmI();
    std::cout << separator << "\n" << std::endl;
   
    diamond3 = diamond1;

    std::cout << separator << "\n" << std::endl;
    diamond3.whoAmI();
    std::cout << separator << "\n" << std::endl;

    for (int i = 0; i < 100; i++)
    {
        diamond1.attack("MOXIII");
    }
    
    std::cout << separator << "\n" <<  std::endl;
    diamond1.beRepaired(10);
    std::cout << separator << "\n" <<  std::endl;

    for (int i = 0; i < 3; i++)
    {
        diamond1.takeDamage(50);
    }

    std::cout << separator << "\n" << std::endl;
    
    return 0;
}
