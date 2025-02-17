#include "FragTrap.hpp"

int main( void )
{
    std::string separator(70, '*');

    FragTrap frag1("FR4G-TP");
    FragTrap frag2(frag1);
    FragTrap frag3;

    frag3 = frag1;

    std::cout << separator << "\n" << std::endl;
    frag1.highFiveGuys();
    std::cout << separator << "\n" << std::endl;

    for (int i = 0; i < 99; i++)
    {
        frag1.attack("MOXIII");
    }
    
    std::cout << separator << "\n" <<  std::endl;
    frag1.beRepaired(10);
    std::cout << separator << "\n" <<  std::endl;

    for (int i = 0; i < 5; i++)
    {
        frag1.takeDamage(50);
    }

    std::cout << separator << "\n" << std::endl;
    frag1.highFiveGuys();
    std::cout << separator << "\n" << std::endl;


    return 0;
}
