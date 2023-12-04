#include "Zombie.hpp"

int main()
{
    Zombie *zm = newZombie("Foo");
    zm->announce();
    randomChump("da7mad");

    delete zm;
    return 0;
}