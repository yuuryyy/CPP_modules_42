#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RRF", 72, 45), _target("RRF")
{
    // std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string target ) : AForm(target, 72, 45), _target(target)
{
    // std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &src ) : AForm(src), _target(src._target)
{
    // std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &src )
{
    // std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
    if (this != &src)
    {
        this->_target = src._target;
    }
    return *this;
}

void RobotomyRequestForm::action( void ) const
{
    std::cout << "DZZZZZZ....DRRRRRRR...." << std::endl;
    std::cout << "Robotomy on " << this->_target << " has been ";

    if (rand() % 2 == 0)
        std::cout << "successful" << std::endl;
    else
        std::cout << "unsuccessful" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
    // std::cout << "RobotomyRequestForm destructor called" << std::endl;
}