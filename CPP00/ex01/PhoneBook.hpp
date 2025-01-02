#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	_contacts[8];
		bool _promptNset(Contact& contact,const std::string msg,int flag);
		bool _inputParser(const std::string& input, bool num);

	public:
		PhoneBook();
		~PhoneBook();

		bool Add(int index);
		bool Search(int ContactNum);
		int Exit();
		void Other();
};


#endif