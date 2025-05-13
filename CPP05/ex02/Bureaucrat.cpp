#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( const std::string name, const int grade ) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat( void ) : _name("default")
{
    this->_grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.getName())
{
    *this = src;
}

Bureaucrat
&Bureaucrat::operator=(const Bureaucrat &src)
{
    if (this != &src)
        this->_grade = src.getGrade();
    return *this;
}


std::string
Bureaucrat::getName() const
{
    return this->_name;
}

int
Bureaucrat::getGrade() const
{
    return this->_grade;
}

void
Bureaucrat::increment( void )
{
    if (this->_grade == 1)
    throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void
Bureaucrat::decrement( void )
{
    if (this->_grade == 150)
    throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

const char*
Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char*
Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
    o << i.getName() << ", bureaucrat grade " << i.getGrade();
    return o;
}

void
Bureaucrat::signForm( AForm &form )
{
    try
    {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void
Bureaucrat::executeForm( AForm const & form )
{
    try
    {
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->_name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

Bureaucrat::~Bureaucrat( void )
{
}
