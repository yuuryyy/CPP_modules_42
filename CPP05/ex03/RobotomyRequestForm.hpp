#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP


#include "AForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>


class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm( void );
        RobotomyRequestForm( const std::string target );
        RobotomyRequestForm( const RobotomyRequestForm &src );
        RobotomyRequestForm &operator=( const RobotomyRequestForm &src );
        ~RobotomyRequestForm( void );

        void action( void ) const;
};




#endif