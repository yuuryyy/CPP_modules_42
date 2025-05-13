#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>


// Classic Pine Tree
#define PINE_TREE \
    "   *   \n"   \
    "  ***  \n"   \
    " ***** \n"   \
    "*******\n"   \
    "   |   \n"

// Minimalist Shrub
#define MINI_SHRUB \
    "  ^  \n"      \
    " / \\ \n"     \
    "/   \\\n"     \
    "  |  \n"

// Bonsai
#define BONSAI \
    "  .  \n"  \
    " /|\\ \n" \
    "  |  \n"

// Holiday Special
#define HOLIDAY_TREE \
    "   *   \n"       \
    "  @@@  \n"       \
    " ***** \n"       \
    "  |||  \n"


class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;

    public:
        ShrubberyCreationForm( void );
        ShrubberyCreationForm( const std::string target );
        ShrubberyCreationForm( const ShrubberyCreationForm &src );
        ShrubberyCreationForm &operator=( const ShrubberyCreationForm &src );
        ~ShrubberyCreationForm( void );

        void action( void ) const;
};

#endif