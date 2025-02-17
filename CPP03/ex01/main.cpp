#include "ScavTrap.hpp"

int main( void )
{
    std::string separator(70, '*');

    ScavTrap scav1("FR4G-TP");
    ScavTrap scav2(scav1);
    ScavTrap scav3;
    
    scav3 = scav1;

    std::cout << separator << "\n" << std::endl;
    for (int i = 0; i < 49; i++)
    {
        scav1.attack("MOXIII");
    }
    
    std::cout << separator << "\n" <<  std::endl;
    scav1.beRepaired(10);
    std::cout << separator << "\n" <<  std::endl;

    for (int i = 0; i < 5; i++)
    {
        scav1.takeDamage(50);
    }

    std::cout << separator << "\n" << std::endl;
    scav1.guardGate();
    std::cout << separator << "\n" << std::endl;

    return 0;
}
