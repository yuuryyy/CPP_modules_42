#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){}

PhoneBook::~PhoneBook(){}

bool IsWhiteSpace(std::string& str)
{
    for(size_t i = 0; i < str.length(); i++)
        if (!std::isspace(str[i]))
            return (false);
    return (true);
}


bool IsAllDigit(std::string& str)
{
    for(size_t i = 0; i < str.length(); i++)
        if (!std::isdigit(str[i]))
            return (false);
    return (true);
}

void    DisplayFill(Contact& contact, std::string msg, int flag)
{
    std::string GetInfo;

    while (true)
    {
        std::cout << msg;
        std::getline(std::cin, GetInfo);
        if (GetInfo.empty() || IsWhiteSpace(GetInfo))
        {
            std::cerr << RED"\n*This can't be an empty field !!*" RESET << std::endl;
            continue;
        }
        else
        {
			if (flag == NUM && IsAllDigit(GetInfo) == false)
			{
				std::cerr << RED"\n*Invalid phone number !!*" RESET << std::endl;
            	continue;
			}
            contact.SetContactField(GetInfo, flag);
            return ;
        }
    }
}

void    PhoneBook::Add(int index)
{
    DisplayFill(this->contacts[index], "\n=> Enter the First name : ", FNAME);
    DisplayFill(this->contacts[index], "\n=> Enter the Last name : ", LNAME);
    DisplayFill(this->contacts[index], "\n=> Enter the Nickname : ", NNAME);
    DisplayFill(this->contacts[index], "\n=> Enter the Phone number : ", NUM);
    DisplayFill(this->contacts[index], "\n=> Enter the Darkest secret : ", SECRET);
}