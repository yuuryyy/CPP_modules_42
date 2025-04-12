#pragma once
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource
{
    private:
        AMateria* _materia[4];

    public:
        MateriaSource( void );
        MateriaSource(const MateriaSource &src);
        MateriaSource &operator=(const MateriaSource &src);
        ~MateriaSource( void );

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};


#endif