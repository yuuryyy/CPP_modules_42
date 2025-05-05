#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form( void ) : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    // std::cout << "Form default constructor called" << std::endl;
}

Form::Form( const std::string name, const int gradeToSign, const int gradeToExecute ) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    // std::cout << "Form constructor called" << std::endl;
    if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    // std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &src)
{
    // std::cout << "Form copy assignment operator called" << std::endl;
    if (this != &src)
    {
        this->_isSigned = src._isSigned;
        // this->_gradeToSign = src._gradeToSign; // Cannot assign to const member
        // this->_gradeToExecute = src._gradeToExecute; // Cannot assign to const member
    }
    return *this;
}

std::string Form::getName() const
{
    return this->_name;
}

bool Form::getIsSigned() const
{
    return this->_isSigned;
}

int Form::getGradeToSign() const
{
    return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

void Form::beSigned( Bureaucrat &bureaucrat )
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    this->_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form: Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form: Grade too low";
}

std::ostream &operator<<(std::ostream &o, Form const &i)
{
    o << "Form: " << i.getName() << ", is signed: " << i.getIsSigned() << ", grade to sign: " << i.getGradeToSign() << ", grade to execute: " << i.getGradeToExecute();
    return o;
}

Form::~Form( void )
{
    // std::cout << "Form destructor called" << std::endl;
}