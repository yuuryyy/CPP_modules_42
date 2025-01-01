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
		bool promptNset(Contact& contact,const std::string msg,int flag);
		bool Search(int ContactNum);
		int Exit();
		bool inputParser(const std::string& input, bool num);
		void Other();
};


#endif