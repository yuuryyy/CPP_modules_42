#ifndef BEAUCRAT_HPP
#define BEAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>


class Bureaucrat
{
        const std::string _name;
        int _grade;
    public:

        Bureaucrat( void );
        Bureaucrat( const std::string name, const int grade );
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat &operator=(const Bureaucrat &src);
        ~Bureaucrat( void );

        std::string getName() const;
        int getGrade() const;

        void increment( void );
        void decrement( void );

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
               const char* what() const throw();
        };

};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)

#endif