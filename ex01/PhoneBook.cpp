#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){}

PhoneBook::~PhoneBook(){}

void	PhoneBook::Add(int index)
{
	std::string fname;
	std::string lname;
	std::string nname;
	std::string number;
	std::string secret;

	if (std::getline(std::cin, fname))
		exit(0);
	
}