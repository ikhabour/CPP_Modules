#include "RPN.hpp"



RPN::RPN() {}

int isSymbol(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

int     RPN::getTop()
{
    int number = this->stack.top();
    this->stack.pop();
    return number;
}

void    RPN::PerformOp(char c)
{
    if (this->stack.size() < 2)
        throw std::runtime_error("Error");
    int n1 = this->getTop();
    int n2 = this->getTop();
    switch (c)
    {
        case '+' :
            this->stack.push(n2 + n1);
            break;
        case '-' :
            this->stack.push(n2 - n1);
            break;
        case '*' :
            this->stack.push(n2 * n1);
            break;
        case '/' :
            if (n1 == 0)
            {
                std::cerr<<"cant divide by 0"<<std::endl;
                throw std::runtime_error("Error");
            }
            this->stack.push(n2 / n1);
            break;
        default :
            break;
    }
}

RPN::RPN(const std::string& expr)
{
    for (size_t i = 0; i < expr.length(); i++)
    {
        if (isspace(expr[i]))
            continue;
        else if (isdigit(expr[i]))
            this->stack.push(expr[i] - 48);
        else if (isSymbol(expr[i]))
            this->PerformOp(expr[i]);
    }
    if (this->stack.size() == 1)
        std::cout<<stack.top()<<std::endl;
    else
        throw std::runtime_error("Error");
}

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN& other)
{
    (void)other;
    return *this;
}


RPN::~RPN() {}