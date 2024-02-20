#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void function(AForm& form, Bureaucrat& b)
{
	try
	{
		b.signForm(form);
		b.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

int main()
{
	//ShrubberyCreationForm s("shrub");

	RobotomyRequestForm r("robot");
	//PresidentialPardonForm p("larbi");
	Bureaucrat e("employee", 25);
	// function(r, e);
	// function(r, e);
	function(r, e);
	return (0);
}