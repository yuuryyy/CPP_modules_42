#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define FNAME  0
#define LNAME  1
#define NNAME  3
#define NUM    4
#define SECRET 5

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

class Contact
{
	private:
		std::string	_FirstName;
		std::string	_LastName;
		std::string	_Nickname;
		std::string	_PhoneNumber;
		std::string	_DarkestSecret;
	public:
		Contact();
		~Contact();

		void SetContactField(const std::string& ContactInfo, int flag);
		void DisplaySearch(int index);
		void DisplayInfo();
};

#endif