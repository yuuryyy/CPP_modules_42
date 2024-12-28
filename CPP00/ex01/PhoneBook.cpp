#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){}

PhoneBook::~PhoneBook(){}

bool    PhoneBook::Add(int index)
{
    if (DisplayFill(this->contacts[index], "\n=> Enter the First name : ", FNAME) == false)
		return false;
    if (DisplayFill(this->contacts[index], "\n=> Enter the Last name : ", LNAME) == false)
		return false;
    if (DisplayFill(this->contacts[index], "\n=> Enter the Nickname : ", NNAME) == false)
		return false;
    if (DisplayFill(this->contacts[index], "\n=> Enter the Phone number : ", NUM) == false)
		return false;
    if (DisplayFill(this->contacts[index], "\n=> Enter the Darkest secret : ", SECRET) == false)
		return false;
	return true;
}


bool	PhoneBook::Search(int ContactNum)
{

	if (ContactNum == -1)
	{
		std::cout << "* There are no saved Contacts yet !!! *" << std::endl;
		return true;
	}

	std::cout << "      |  Index   |First name|Last name | Nikname  |    " << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;

	for(int i = 0; i <= ContactNum; i++)
	{
		this->contacts[i].DisplaySearch(i);
	}

	std::string	GetIndex;

	while (true)
	{
		std::cout << "\nEnter the index of the entry to display : ";
		std::getline(std::cin, GetIndex);

		if (std::cin.eof() || std::cin.fail())
			return false;

		if (GetIndex.empty() ||  !IsAllDigit(GetIndex)
			|| IsWhiteSpace(GetIndex) || GetIndex.length() > 1)
		{
			std::cerr << RED"\n*Invalid character/out of range !!*" RESET << std::endl;
			continue ;
		}

		std::stringstream	str(GetIndex);
		int					index;

		str >> index;
		if (index > ContactNum)
			std::cerr << RED"\n*The index " << GetIndex
				<< " is out of range/wrong*" RESET << std::endl;

		else
		{
			this->contacts[index].DisplayInfo();
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
	std::cerr << RED"\nInvalid option !!\n" RESET << std::endl;
}