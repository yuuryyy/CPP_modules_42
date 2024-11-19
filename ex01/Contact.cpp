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

