#include "PmergeMe.hpp"
#include <exception>

int main(int ac, char **av)
{
	if (ac == 1 || ac == 2)
	{
		std::cout << "Please enter a sequence of integers."<< std::endl;
		return (1);
	}
	try 
	{
		PmergeMe e(ac, av);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
