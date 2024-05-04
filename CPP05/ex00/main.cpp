#include "Bureaucrat.hpp"

int main( void )
{
    try 
    {
        Bureaucrat bureaucrat("ash", 150);

        std::cout << bureaucrat << std::endl;

        bureaucrat.decrement();
    } 
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl; 
    }
    try
    {
        Bureaucrat bureaucrat("ash1", 1);

        std::cout << bureaucrat << std::endl;

        bureaucrat.increment();
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl; 
    }
    
    return 0;
}