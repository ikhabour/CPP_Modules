#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>

class PmergeMe
{
    private:
        std::vector<int> vec;
        std::deque<int> deq;
        template <typename T>
        int     Duplicates(T& container);
        void    Magic();
        template <typename T>
        clock_t     sort(T& container);
        template <typename T>
        void    Display(T& container);
        template <typename T>
        int     BinarySearch(int left, int right, int value, T& vec);
    public:
        PmergeMe();
        PmergeMe(int argc, char **argv);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

};