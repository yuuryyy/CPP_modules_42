#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
    // std::cout << "MateriaSource default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
    // std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (src._materia[i])
            _materia[i] = src._materia[i]->clone();
        else
            _materia[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
    // std::cout << "MateriaSource assignment operator called" << std::endl;
    if (this != &src)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_materia[i])
                delete _materia[i];
            if (src._materia[i])
                _materia[i] = src._materia[i]->clone();
            else
                _materia[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource( void )
{   
    // std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        if (_materia[i])
            delete _materia[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
    // std::cout << "MateriaSource learnMateria method called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i] == NULL)
        {
            _materia[i] = m;
            return;
        }
    }
    std::cout << "MateriaSource: No more space to learn new materia." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    // std::cout << "MateriaSource createMateria method called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i] && _materia[i]->getType() == type)
            return _materia[i]->clone();
    }
    std::cout << "MateriaSource: No materia of type " << type << " found." << std::endl;
    return NULL;
}