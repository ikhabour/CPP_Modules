#include "Zombie.hpp"

int main()
{
    Zombie *ptr = zombieHorde(5, "Foo");

    for (int i = 0; i < 5; i++)
        ptr[i].announce();
    delete[] ptr;
}