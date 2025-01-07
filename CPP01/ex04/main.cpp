# include "SedIsFolosers.hpp"

void	error(const std::string& errname,const std::string& spec)
{
	std::cerr << "Error:  \n" << errname;
	if (spec != "")
		std::cerr << RED << spec << RESET;
	std::cerr << std::endl;
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return error("Invalid argument => ", "<filename> s1 s2."), 1;

	std::ifstream	infile(av[1]);
	if (!infile || !infile.is_open())
		return error("failed to open a file =>", std::string(av[1])), 1;

	std::string	repFilename = std::string(av[1]) + ".replace";
	std::ofstream	repFile(repFilename, std::ios::trunc);
	if (!repFile || !repFile.is_open())
		return  infile.close(), error("failed to open a file =>", repFilename), 1;

	if (!CopynReplace(infile, repFile, std::string(av[2]), std::string(av[3])))
		return 1;

	infile.close();
	repFile.close();

	return (0);
}