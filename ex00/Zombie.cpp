#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;

    std::cerr << "Construct " << this->name << std::endl;
}

Zombie::~Zombie(void)
{
    std::cerr << "Destruct " << this->name << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
