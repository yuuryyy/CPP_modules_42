#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
    private:

        std::string ideas[100];

    public:

        Brain( void);
        Brain( const Brain &copy );

        Brain &operator=( const Brain &copy );

        std::string getIdea( int index ) const;
        void setIdea( int index, const std::string idea );

        ~Brain();
    };

#endif
