#include "Character.hpp"

Character::Character( void ) : _name("Default"), _count(-1)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character( const std::string& name ) : _name(name), _count(-1)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character( const Character& other ) : _name(other._name), _count(other._count)
{
    for (int i = 0; i < 4; i++)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
}

Character&
Character::operator=( const Character& other )
{
    if (this != &other)
    {
        _name = other._name;
        _count = other._count;
        for (int i = 0; i < 4; i++)
        {
            if (_inventory[i])
                delete _inventory[i];
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character( void )
{
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
    }
}

const std::string&
Character::getName( void ) const
{
    return _name;
}

void
Character::equip( AMateria* m )
{
    if (_count < 3 && m)
    {
        _inventory[++_count] = m;
    }
}

void
Character::unequip( int idx )
{
    if (idx >= 0 && idx <= 3)
    {
        if (_inventory[idx])
        {   
            _inventory[idx] = NULL;
            _count--;
        }
    }
}

void
Character::use( int idx, ICharacter& target )
{
    if (idx >= 0 && idx <= 3)
    {
        if (_inventory[idx])
            _inventory[idx]->use(target);
    }
}