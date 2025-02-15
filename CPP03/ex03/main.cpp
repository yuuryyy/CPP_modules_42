#include "DiamondTrap.hpp"

int main( void )
{

    std::string str(70, '-');

    DiamondTrap diamondTrap("yoooo");
    diamondTrap.attack("target");
    diamondTrap.guardGate();
    diamondTrap.whoAmI();
    
    std::cout << str << std::endl;

    DiamondTrap diamondTrap2(diamondTrap);
    diamondTrap2.whoAmI();

    std::cout << str<< std::endl;

    DiamondTrap diamondTrap3 = diamondTrap2;
    diamondTrap3.whoAmI();

    std::cout << str<< std::endl;

    return 0;
}
