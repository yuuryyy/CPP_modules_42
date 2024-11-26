# include "Harl.hpp"

void	error(const std::string errname, std::string spec)
{
	std::cerr << "Error:  \n" << errname;
	if (spec.compare(""))
		std::cerr << RED << spec << RESET;
	std::cerr << std::endl;
	exit(1);
}

void	errLvl( Harl obj )
{
	std::cout << "[ ERROR ]" << std::endl;
	obj.complain("ERROR");
	std::cout << std::endl;

}

void	wrnLvl( Harl obj )
{
	std::cout << "[ WARNING ]" << std::endl;
	obj.complain("WARNING");
	std::cout << std::endl;

	errLvl(obj);
}

void	infLvl( Harl obj )
{
	std::cout << "[ INFO ]" << std::endl;
	obj.complain("INFO");
	std::cout << std::endl;


	wrnLvl(obj);
}

void	dbgLvl( Harl obj )
{
	std::cout << "[ DEBUG ]" << std::endl;
	obj.complain("DEBUG");
	std::cout << std::endl;

	infLvl(obj);
}

int	main(int ac, char **av)
{
	Harl		obj;
	std::string	lvl[] = {"DEBUG", "INFO","WARNING", "ERROR"};
	int			i = 0;

	if (ac != 2)
		error("Invalid arguments => ", "./harlFilter LEVEL");

	while (lvl[i].compare(av[1]) != 0)
		i++;

	switch(i)
	{
		case 0:
			dbgLvl(obj);
			break ;
		case 1:
			infLvl(obj);
			break;
		case 2:
			wrnLvl(obj);
			break;
		case 3:
			errLvl(obj);
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

	return EXIT_SUCCESS;
}