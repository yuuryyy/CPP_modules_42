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
		void Search();
		void Exit();
		void Other();
};


#endif