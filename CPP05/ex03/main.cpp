#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Intern random;

	AForm *ref = random.makeForm("shrubbery request", "bender");
	if (ref)
		std::cout << *ref << std::endl;
	return (0);
}