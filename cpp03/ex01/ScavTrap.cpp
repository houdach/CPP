#include "ScavTrap.hpp"

void ScavTrap :: guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout<<"ScavTrap constructor has been called"<<std::endl;
}
