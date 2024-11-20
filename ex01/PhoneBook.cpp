#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){}

PhoneBook::~PhoneBook(){}

void    PhoneBook::Add(int index)
{
    DisplayFill(this->contacts[index], "\n=> Enter the First name : ", FNAME);
    DisplayFill(this->contacts[index], "\n=> Enter the Last name : ", LNAME);
    DisplayFill(this->contacts[index], "\n=> Enter the Nickname : ", NNAME);
    DisplayFill(this->contacts[index], "\n=> Enter the Phone number : ", NUM);
    DisplayFill(this->contacts[index], "\n=> Enter the Darkest secret : ", SECRET);
}

void	PhoneBook::Search(int ContactNum)
{

	if (ContactNum == -1)
	{
		std::cout << "* There are no saved Contacts yet !!! *" << std::endl;
		return ;
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
		if (GetIndex.empty() ||  !IsAllDigit(GetIndex)
			|| IsWhiteSpace(GetIndex) || GetIndex.length() > 1)
		{
			std::cerr << RED"\n*Invalid character/out of range !!*" RESET << std::endl;
			continue ;
		}

		if (std::stoi(GetIndex) > ContactNum)
			std::cerr << RED"\n*The index " << GetIndex
				<< " is out of range/wrong*" RESET << std::endl;

		else
		{
			this->contacts[std::stoi(GetIndex)].DisplayInfo();
			break ;
		}
	}
	return ;
}

void	PhoneBook::Exit()
{
	std::cout << BLUE"\nExiting Phonebook ^*^.\n" RESET << std::endl;
	exit (0);
}

void	PhoneBook::Other()
{
	std::cerr << RED"\nInvalid option !!\n" RESET << std::endl;
}