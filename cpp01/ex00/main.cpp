#include "Zombie.hpp"

int main(void)
{
    Zombie *zombie = newZombie("newZombie");
    zombie->announce();
    delete zombie;

    randomChump("randomChump");

    return (0);
}
