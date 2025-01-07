#ifndef SEDISFOLOSERS_HPP
#define SEDISFOLOSERS_HPP

#include <iostream>
#include <fstream>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

bool	CopynReplace(std::ifstream& infile, std::ofstream& outfile,const std::string& s1,const std::string& s2);
void	error(const std::string& errname,const std::string& spec);


#endif