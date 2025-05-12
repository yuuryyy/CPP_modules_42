#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("SCF", 145, 137), _target("SCF")
{
    // std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target ) : AForm("SCF", 145, 137), _target(target)
{
    // std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &src ) : AForm(src), _target(src._target)
{
    // std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &src )
{
    // std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
    if (this != &src)
    {
        this->_target = src._target;
    }
    return *this;
}

void ShrubberyCreationForm::action( void ) const
{
    std::ofstream file;
    file.open(this->_target + "_shrubbery");
    if (!file.is_open())
    {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    file << PINE_TREE << std::endl;
    file << MINI_SHRUB << std::endl;
    file << BONSAI << std::endl;
    file << HOLIDAY_TREE << std::endl;

    file.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
    // std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}
