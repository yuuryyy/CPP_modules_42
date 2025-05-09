#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm( void ) : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    // std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm( const std::string name, const int gradeToSign, const int gradeToExecute ) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    // std::cout << "AForm constructor called" << std::endl;
    if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    // std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &src)
{
    // std::cout << "AForm copy assignment operator called" << std::endl;
    if (this != &src)
    {
        this->_isSigned = src._isSigned;
        // this->_gradeToSign = src._gradeToSign; // Cannot assign to const member
        // this->_gradeToExecute = src._gradeToExecute; // Cannot assign to const member
    }
    return *this;
}

std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::getIsSigned() const
{
    return this->_isSigned;
}

int AForm::getGradeToSign() const
{
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

void AForm::beSigned( Bureaucrat &bureaucrat )
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
    this->_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm: Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm: Grade too low";
}

std::ostream &operator<<(std::ostream &o, AForm const &i)
{
    o << "AForm: " << i.getName() << ", is signed: " << i.getIsSigned() << ", grade to sign: " << i.getGradeToSign() << ", grade to execute: " << i.getGradeToExecute();
    return o;
}

void AForm::execute( Bureaucrat const & executor ) const
{
    if (!this->_isSigned)
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > this->_gradeToExecute)
        throw AForm::GradeTooLowException();
    this->action();
}

AForm::~AForm( void )
{
    // std::cout << "AForm destructor called" << std::endl;
}