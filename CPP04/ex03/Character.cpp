#include "Character.hpp"

Character::Character( void ) :  _name("Default"), _count(-1)
{
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character( const std::string& name ) : _name(name), _count(-1)
{
    std::cout << "Character " << _name << " constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character( const Character& other ) : _name(other._name), _count(other._count)
{
    std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (other._inventory[i])
            this->_inventory[i] = other._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }
}

Character&
Character::operator=( const Character& other )
{
    std::cout << "Character assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_count = other._count;
        for (int i = 0; i < 4; i++)
        {
            if (this->_inventory[i])
                delete this->_inventory[i];
            if (other._inventory[i])
                this->_inventory[i] = other._inventory[i]->clone();
            else
                this->_inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character( void )
{
    std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
    }
}

const std::string&
Character::getName( void ) const
{
    // std::cout << "Character getName method called" << std::endl;
    return _name;
}

void
Character::equip( AMateria* m )
{
    std::cout << "Character equip method called" << std::endl;
    if (_count < 3 && m)
        _inventory[++_count] = m;
}

void
Character::unequip( int idx )
{
    std::cout << "Character unequip method called" << std::endl;
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
    std::cout << "Character " << _name << " use method called" << std::endl;
    if (idx >= 0 && idx <= 3)
    {
        if (_inventory[idx])
            _inventory[idx]->use(target);
    }
}