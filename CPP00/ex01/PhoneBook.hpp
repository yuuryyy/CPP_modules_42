#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		bool promptNset(Contact& contact,const std::string msg,int flag);
		bool inputParser(const std::string& input, bool num);

	public:
		PhoneBook();
		~PhoneBook();

		bool Add(int index);
		bool Search(int ContactNum);
		int Exit();
		void Other();
};


#endif