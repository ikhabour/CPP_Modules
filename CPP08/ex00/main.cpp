#include "easyfind.hpp"
#include <algorithm>
#include <vector>
#include <list>


int main()
{
    std::list<int> list;

    for (int i = 0; i < 10; i++)
        list.push_back(i);
    easyfind(list, 1000);
}