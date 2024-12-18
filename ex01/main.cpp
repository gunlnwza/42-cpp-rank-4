#include "Zombie.hpp"

#define N 5
#define NAME "zombie in the horde"

int main(void)
{
    Zombie *horde = zombieHorde(N, NAME);

    for (int i = 0; i < N; i++)
        horde[i].announce();

    delete[] horde;

    return (0);
}
