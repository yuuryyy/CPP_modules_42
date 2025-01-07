#include "Contact.hpp"


Contact::Contact()
{
	_FirstName = "";
	_LastName = "";
	_Nickname = "";
	_PhoneNumber = "";
	_DarkestSecret = "";
}


Contact::~Contact()
{
	_FirstName = "";
	_LastName = "";
	_Nickname = "";
	_PhoneNumber = "";
	_DarkestSecret = "";
}


void	Contact::SetContactField(const std::string& ContactInfo, int flag)
{
	if (flag == FNAME)
		_FirstName = ContactInfo;
	else if (flag == LNAME)
		_LastName = ContactInfo;
	else if (flag == NNAME)
		_Nickname = ContactInfo;
	else if (flag == NUM)
		_PhoneNumber = ContactInfo;
	else if (flag == SECRET)
		_DarkestSecret = ContactInfo;
}

const std::string	Contact::_FitColumns(const std::string& Info)
{
	if (Info.length() > 10)
		return (Info.substr(0, 9) + ".|");
	else
	{
		int			space_num = (10 - Info.length());
		std::string	Spaces(space_num, ' ');
			return (Spaces +Info + "|");
	}
	return (Info);
}

void	Contact::DisplaySearch(const int index)
{
	std::cout << "      |    " << index << "     |" << _FitColumns(_FirstName)
	<< _FitColumns(_LastName) << _FitColumns(_Nickname) << std::endl;
}

void	Contact::DisplayInfo()
{
	std::cout << MAGENTA "\nFirst name 	 : " RESET <<_FirstName << std::endl;
	std::cout << MAGENTA "Last name  	 : " RESET << _LastName << std::endl;
	std::cout << MAGENTA "Nickname   	 : " RESET << _Nickname << std::endl;
	std::cout << MAGENTA "Phone number     : " RESET << _PhoneNumber << std::endl;
	std::cout << MAGENTA "Darkest secret   : " RESET << _DarkestSecret + "\n" << std::endl;
}
