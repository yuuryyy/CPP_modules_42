#pragma once
#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>


class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;

    public:
        AForm( void );
        AForm( const std::string name, const int gradeToSign, const int gradeToExecute );
        AForm(const AForm &src);
        AForm &operator=(const AForm &src);
        virtual ~AForm( void );

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned( Bureaucrat &bureaucrat );
        void execute( Bureaucrat const & executor ) const;
        virtual void action() const = 0;

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

        class FormNotSignedException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &o, AForm const &i);

#endif