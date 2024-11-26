#include "Contact.hpp"


Contact::Contact()
{
	this->FirstName = "";
	this->LastName = "";
	this->Nickname = "";
	this->PhoneNumber = "";
	this->DarkestSecret = "";
}


Contact::~Contact()
{
	this->FirstName = "";
	this->LastName = "";
	this->Nickname = "";
	this->PhoneNumber = "";
	this->DarkestSecret = "";
}


void	Contact::SetContactField(std::string ContactInfo, int flag)
{
	if (flag == FNAME)
		this->FirstName = ContactInfo;
	else if (flag == LNAME)
		this->LastName = ContactInfo;
	else if (flag == NNAME)
		this->Nickname = ContactInfo;
	else if (flag == NUM)
		this->PhoneNumber = ContactInfo;
	else if (flag == SECRET)
		this->DarkestSecret = ContactInfo;
}

std::string	TruncateString(const std::string& str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".|");
	else
	{
		int			space_num = (10 - str.length());
		std::string	Spaces(space_num / 2, ' ');
		if (space_num % 2 == 0)
			return (Spaces + str + Spaces + "|");
		else
			return (Spaces + str + Spaces + " |");
	}
	return (str);
}

void	Contact::DisplaySearch(int index)
{
	std::cout << "      |    " << index << "     |" << TruncateString(this->FirstName)
	<< TruncateString(this->LastName) << TruncateString(this->Nickname) << std::endl;
}

void	Contact::DisplayInfo()
{
	std::cout << MAGENTA "\nFirst name 	 : " RESET << this->FirstName << std::endl;
	std::cout << MAGENTA "Last name  	 : " RESET << this->LastName << std::endl;
	std::cout << MAGENTA "Nickname   	 : " RESET << this->Nickname << std::endl;
	std::cout << MAGENTA "Phone number     : " RESET << this->PhoneNumber << std::endl;
	std::cout << MAGENTA "Darkest secret   : " RESET << this->DarkestSecret + "\n" << std::endl;
}
