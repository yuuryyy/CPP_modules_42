#include <iostream>

int main()
{

	std::string	StrTest("HI THIS IS BRAIN");
	std::string* stringPTR = &StrTest;
	std::string& stringREF = StrTest;

	{
		std::cout << "The memory address of the string variable :[";
		std::cout << &StrTest <<  "]." << std::endl;

		std::cout << "The memory address held by stringPTR      :[";
		std::cout << stringPTR << "]." << std::endl;

		std::cout << "The memory address held by stringREF      :[";
		std::cout << &stringREF << "]." << std::endl;

	}

	std::cout << "--------------------------------------------------------------" << std::endl;

	{

		std::cout << "The value of the string variable          :{ ";
		std::cout << StrTest + " }." << std::endl;
	
		std::cout << "The value pointed to by stringPTR         :{ ";
		std::cout << *stringPTR + " }." << std::endl;
	
		std::cout << "The value of the string variable          :{ ";
		std::cout << stringREF << " }." << std::endl;
	}

	return EXIT_SUCCESS;
}