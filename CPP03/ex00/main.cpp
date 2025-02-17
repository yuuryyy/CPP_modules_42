#include "ClapTrap.hpp"

int main( void )
{
    std::string separator(70, '*');

    ClapTrap clap1("FR4G-TP");
    ClapTrap clap2(clap1);
    ClapTrap clap3;
    
    clap3 = clap1;

    std::cout << separator << "\n" << std::endl;
    for (int i = 0; i < 9; i++)
    {
        clap1.attack("MOXIII");
    }
    
    std::cout << separator << "\n" <<  std::endl;
    clap1.beRepaired(10);
    std::cout << separator << "\n" <<  std::endl;

    for (int i = 0; i < 5; i++)
    {
        clap1.takeDamage(5);
    }

    std::cout << separator << "\n" << std::endl;
    return 0;
}
