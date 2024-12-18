#include "Zombie.hpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    Zombie *zombie = newZombie("newZombie");
    zombie->announce();
    delete zombie;

    randomChump("randomChump");

    return (0);
}
