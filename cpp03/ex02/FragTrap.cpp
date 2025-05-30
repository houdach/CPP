#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    Hit_points = 100;
    Energy_points = 100;
    Attack_damage = 30;
    std::cout << "FragTrap constructor has been called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor has been called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << Name << " requests a HIGH FIVE! ✋😄" << std::endl;
}