#pragma once

#include <iostream>
#include <stack>

class RPN
{
    private:
        std::stack<double> stack;
        void    PerformOp(char c);
        int     getTop();
    public:
        RPN();
        RPN(const std::string& expr);
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();
};