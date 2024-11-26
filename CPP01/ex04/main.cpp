# include "SedIsFolosers.hpp"

void	error(const std::string errname, std::string spec)
{
	std::cerr << "Error:  \n" << errname;
	if (spec.compare(""))
		std::cerr << RED << spec << RESET;
	std::cerr << std::endl;
	exit(1);
}

int	main(int ac, char **av)
{
	if (ac != 4)
		error("Invalid argument => ", "<filename> s1 s2.");

	std::ifstream	infile(av[1]);
	if (!infile.is_open())
		error("failed to open a file =>", std::string(av[1]));

	std::string	repFilename = std::string(av[1]) + ".replace";
	std::ofstream	repFile(repFilename, std::ios::trunc);
	if (!repFile.is_open())
		error("failed to open a file =>", repFilename);

	CopynReplace(infile, repFile, std::string(av[2]), std::string(av[3]));

	infile.close();
	repFile.close();

	return (0);
}