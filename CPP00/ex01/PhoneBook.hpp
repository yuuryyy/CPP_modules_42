#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
	public:
		PhoneBook();
		~PhoneBook();

		bool Add(int index);
		bool Search(int ContactNum);
		int Exit();
		void Other();
};

bool 	IsAllDigit(const std::string& str);
bool	IsWhiteSpace(const std::string& str);
bool    DisplayFill(Contact& contact, std::string msg, int flag);

#endif