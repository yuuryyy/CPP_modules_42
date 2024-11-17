#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

#define FNAME  0
#define LNAME  1
#define NNAME  3
#define NUM    4
#define SECRET 5

class Contact
{
	private:
		std::string	FirstName;
		std::string	LastName;
		std::string	Nickname;
		std::string	PhoneNumber;
		std::string	DarkestSecret;
	public:
		Contact();
		~Contact();

		void SetContactField(std::string ContactInfo, int flag);
};

#endif