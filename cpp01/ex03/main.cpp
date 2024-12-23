#include "HumanA.hpp"
#include "HumanB.hpp"

void testHumanA(void)
{
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
}

void testHumanB(void)
{
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
}

int main(void)
{
    testHumanA();
    testHumanB();
    return (0);
}
