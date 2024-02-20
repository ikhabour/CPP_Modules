#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP


#include "Form.hpp"
#include <exception>
#include <iostream>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string Name, int Grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        void    increment();
        void    decrement();

        // Getters
        std::string getName() const;
        int getGrade() const;

        // others
        void signForm(Form& f);

        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() throw()
                {
                    return ("Grade too High");
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() throw()
                {
                    return ("Grade too Low");
                }
        };
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& other);








#endif