#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    Hit_points = 100;
    Energy_points = 50;
    Attack_damage = 20;
    std::cout << "ScavTrap constructor has been called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor has been called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (Energy_points == 0 || Hit_points == 0)
    {
        std::cout << "ScavTrap " << Name << " has no energy or is dead and cannot attack!" << std::endl;
        return;
    }
    Energy_points--;
    std::cout << "ScavTrap " << Name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << Name << " is now in Gate keeper mode." << std::endl;
}