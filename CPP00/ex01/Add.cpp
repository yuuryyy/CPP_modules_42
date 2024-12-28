#include "PhoneBook.hpp"

bool IsWhiteSpace(const std::string& str)
{

    for(size_t i = 0; i < str.length(); i++)
    {
        if (!std::isspace(str[i]) && std::isalnum(str[i]))
            return (false);
    }

    return (true);
}


bool IsAllDigit(const std::string& str)
{

    for(size_t i = 0; i < str.length(); i++)
        if (!std::isdigit(str[i]))
            return (false);

    return (true);
}

bool    DisplayFill(Contact& contact,const std::string msg, int flag)
{
    std::string GetInfo;

    while (true)
    {
        std::cout << msg;
        std::getline(std::cin, GetInfo);

        if (std::cin.eof() || std::cin.fail())
            return (false);

        if (GetInfo.empty() || IsWhiteSpace(GetInfo))
        {
            std::cerr << RED"\n*This can't be an empty field/contains unprintable characters !!*" RESET << std::endl;
            continue;
        }

        else
        {
			if (flag == NUM && IsAllDigit(GetInfo) == false)
			{
            	std::cerr << RED"\n*Phone number should only contain digits!!*" RESET << std::endl;
				continue ;
			}

            contact.SetContactField(GetInfo, flag);
            return true;
        }
    }

    return true;
}