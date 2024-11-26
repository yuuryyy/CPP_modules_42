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

		void Add(int index);
		void Search(int ContactNum);
		void Exit();
		void Other();
};

bool 	IsAllDigit(const std::string& str);
bool	IsWhiteSpace(const std::string& str);
void    DisplayFill(Contact& contact, std::string msg, int flag);

#endif