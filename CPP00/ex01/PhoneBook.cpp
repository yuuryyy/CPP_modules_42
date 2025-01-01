#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){}

PhoneBook::~PhoneBook(){}

bool    PhoneBook::promptNset(Contact& contact,const std::string msg,int flag)
{
    std::string GetInfo;

    while (true)
    {
        std::cout << msg;
        getline(std::cin, GetInfo);
		std::cout << "heere\n";
        if (std::cin.eof() || std::cin.fail())
            return (false);

       if (flag == NUM && !this->inputParser(GetInfo, true))
        {
        	std::cerr << RED"\n*Phone number should only contain digits!!*" RESET << std::endl;
			continue ;
		}
        else if (!this->inputParser(GetInfo, false))
        {
        	std::cerr << RED"\n* Invalid information!!*" RESET << std::endl;
			continue ;
        }
        contact.SetContactField(GetInfo, flag);
        return true;

    }

    return true;
}

bool    PhoneBook::Add(int index)
{

	int i = index;

	if (index > 7)
		i = index - 8;
    if (!this->promptNset(this->contacts[i], "\n=> Enter the First name : ", FNAME))
		return false;
    if (!this->promptNset(this->contacts[i], "\n=> Enter the Last name : ", LNAME))
		return false;
    if (!this->promptNset(this->contacts[i], "\n=> Enter the Nickname : ", NNAME))
		return false;
    if (!this->promptNset(this->contacts[i], "\n=> Enter the Phone number : ", NUM))
		return false;
    if (!this->promptNset(this->contacts[i], "\n=> Enter the Darkest secret : ", SECRET))
		return false;
	return true;
}


bool	PhoneBook::inputParser(const std::string& input, bool num)
{
	size_t	i = 0;

	if (input.empty())
		return false;

	for(i = 0; i < input.length(); i++)
    {
        if (!std::isspace(input[i]) && std::isalnum(input[i]))
            break ;
    }

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

bool	PhoneBook::Search(int ContactNum)
{

	if (ContactNum == -1)
	{
		std::cout << "* There are no saved Contacts yet !!! *" << std::endl;
		return true;
	}

	std::cout << "      |  Index   |First name|Last name | Nikname  |    " << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;

	if (ContactNum > 7)
		ContactNum = 7;

	for(int i = 0; i <= ContactNum; i++)
	{
		this->contacts[i].DisplaySearch(i);
	}

	std::string	GetIndex;

	while (true)
	{
		std::cout << "\nEnter the index of the entry to display : ";
		getline(std::cin, GetIndex);;

		if (std::cin.eof() || std::cin.fail())
			return false;

		if (!this->inputParser(GetIndex, true) || GetIndex.length() > 1)
		{
			std::cerr << RED"\n*Invalid index !!*" RESET << std::endl;
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