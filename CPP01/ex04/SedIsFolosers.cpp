#include "SedIsFolosers.hpp"

void	Replace(std::string& buff, int index,const std::string& s1, const std::string& s2)
{
	std::string	beforeS1;
	std::string	occurence;
	std::string	afterS1;

	if (index > 0)
	 	beforeS1 = buff.substr(0, index);
	occurence = s2;
	afterS1 = buff.substr(index + s1.length());
	buff = beforeS1 + occurence + afterS1;
}

bool	CopynReplace(std::ifstream& infile, std::ofstream& outfile,const std::string& s1,const std::string& s2)
{
	std::string	buff;
	size_t		index;
	bool		isEOF;

	while (std::getline(infile, buff))
	{
		isEOF = infile.eof();
		if (infile.bad())
           return (error("Error while reading file", ""), infile.close(), outfile.close(), false);
		index = buff.find(s1);
		while (index != std::string::npos)
		{
			Replace(buff, index, s1, s2);
			index = buff.find(s1);
		}
		outfile << buff;
		if (!isEOF)
			outfile << std::endl;
	}
	return (true);
}