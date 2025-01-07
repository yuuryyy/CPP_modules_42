#include "PhoneBook.hpp"


int PhoneBook::_ContactsNb = 0;

PhoneBook::PhoneBook(){}

PhoneBook::~PhoneBook(){}


void	PhoneBook::clear()
{
	std::cin.clear();
	std::cin.ignore(1000, '\n');
}


bool    PhoneBook::_promptNset(Contact& contact,const std::string& msg,int flag)
{
    std::string GetInfo;

    while (true)
    {
        std::cout << msg;
		std::cin >> GetInfo;

        if (std::cin.eof() || std::cin.fail())
            return (false);
		clear();

       if (flag == NUM && !_inputParser(GetInfo, true))
        {
        	std::cerr << RED"\n*Phone number should only contain digits!!*" RESET << std::endl;
			continue ;
		}
        else if (!_inputParser(GetInfo, false))
        {
        	std::cerr << RED"\n* Invalid information!!*" RESET << std::endl;
			continue ;
        }
        contact.SetContactField(GetInfo, flag);
        return true;
    }

    return true;
}

bool    PhoneBook::Add(const int index)
{

	_ContactsNb++;

    if (!_promptNset(_contacts[index], "\n=> Enter the First name : ", FNAME))
		return false;
    if (!_promptNset(_contacts[index], "\n=> Enter the Last name : ", LNAME))
		return false;
    if (!_promptNset(_contacts[index], "\n=> Enter the _Nickname : ", NNAME))
		return false;
    if (!_promptNset(_contacts[index], "\n=> Enter the Phone number : ", NUM))
		return false;
    if (!_promptNset(_contacts[index], "\n=> Enter the Darkest secret : ", SECRET))
		return false;
	return true;
}


bool	PhoneBook::_inputParser(const std::string& input, bool num)
{
	size_t	i = 0;

	if (input.empty())
		return false;

	for(i = 0; i < input.length(); i++)
    {
        if (!std::isspace(input[i]) && !std::isalnum(input[i]))
			return false;
    }

	if (num)
	{
		for(i = 0; i < input.length(); i++)
        	if (!std::isdigit(input[i]))
            	return false;
	}
	return true;
}

bool	PhoneBook::Search()
{

	if (_ContactsNb == 0)
	{
		std::cout << "* There are no saved Contacts yet !!! *" << std::endl;
		return true;
	}

	std::cout << "      |  Index   |First name|Last name | Nikname  |    " << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;

	if (_ContactsNb > 8)
		_ContactsNb = 8;

	for(int i = 0; i < _ContactsNb; i++)
		_contacts[i].DisplaySearch(i);

	int GetIndex;

	while (true)
	{
		std::cout << "\nEnter the index of the entry to display : ";
		std::cin >> GetIndex;

		if (std::cin.eof())
			return false;

		if (std::cin.fail())
		{
				clear();
				std::cerr << RED"\n*Invalid input!!*" RESET << std::endl;
				continue;
		}
		clear();

		if (GetIndex > _ContactsNb - 1 || GetIndex < 0)
			std::cerr << RED"\n*The index " << GetIndex	<< " is out of range/wrong*" RESET << std::endl;
		else
		{
			_contacts[GetIndex].DisplayInfo();
			break ;
		}
	}
	return (true);
}

int	PhoneBook::Exit()
{
	std::cout << BLUE"\nExiting Phonebook ^*^.\n" RESET << std::endl;
	return (0);
}

void	PhoneBook::Other()
{
	clear();
	std::cerr << RED"\nInvalid option !!\n" RESET << std::endl;
}