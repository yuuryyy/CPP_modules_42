#include "Contact.hpp"


Contact::Contact()
{
	this->_FirstName = "";
	this->_LastName = "";
	this->_Nickname = "";
	this->_PhoneNumber = "";
	this->_DarkestSecret = "";
}


Contact::~Contact()
{
	this->_FirstName = "";
	this->_LastName = "";
	this->_Nickname = "";
	this->_PhoneNumber = "";
	this->_DarkestSecret = "";
}


void	Contact::SetContactField(const std::string& ContactInfo, int flag)
{
	if (flag == FNAME)
		this->_FirstName = ContactInfo;
	else if (flag == LNAME)
		this->_LastName = ContactInfo;
	else if (flag == NNAME)
		this->_Nickname = ContactInfo;
	else if (flag == NUM)
		this->_PhoneNumber = ContactInfo;
	else if (flag == SECRET)
		this->_DarkestSecret = ContactInfo;
}

const std::string	Contact::fitSearchDisplay(const std::string& Info)
{
	if (Info.length() > 10)
		return (Info.substr(0, 9) + ".|");
	else
	{
		int			space_num = (10 -Info.length());
		std::string	Spaces(space_num / 2, ' ');
		if (space_num % 2 == 0)
			return (Spaces +Info + Spaces + "|");
		else
			return (Spaces +Info + Spaces + " |");
	}
	return (Info);
}

void	Contact::DisplaySearch(const int index)
{
	std::cout << "      |    " << index << "     |" << fitSearchDisplay(this->_FirstName)
	<< fitSearchDisplay(this->_LastName) << fitSearchDisplay(this->_Nickname) << std::endl;
}

void	Contact::DisplayInfo()
{
	std::cout << MAGENTA "\nFirst name 	 : " RESET << this->_FirstName << std::endl;
	std::cout << MAGENTA "Last name  	 : " RESET << this->_LastName << std::endl;
	std::cout << MAGENTA "Nickname   	 : " RESET << this->_Nickname << std::endl;
	std::cout << MAGENTA "Phone number     : " RESET << this->_PhoneNumber << std::endl;
	std::cout << MAGENTA "Darkest secret   : " RESET << this->_DarkestSecret + "\n" << std::endl;
}