 #include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    Name = name;
    Hit_points = 10;
    Energy_points = 10;
    Attack_damage = 0;
    std::cout<<"constructor has been called"<<std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if(Energy_points == 0 || Hit_points == 0)
    {
        std::cout << "ClapTrap " << Name << " has no energy or is dead and cannot attack!" << std::endl;
        return ;
    }
    Energy_points--;
    std::cout<<Name<<" attacks "<<target<<" causing "<<Attack_damage<<" points of damage!"<<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
     if (Hit_points <= 0) {
        std::cout << "ClapTrap " << Name << " is already destroyed!" << std::endl;
        return;
    }
    Hit_points -= amount;

}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(Energy_points == 0 || Hit_points == 0)
    {
        std::cout<<"ClapTrap  has no energy or is dead and cannot be repaired"<<std::endl;
        return();
    }
    Energy_points--;
    Hit_points+=amount;
    std::cout<<"damage repaired!"<<std::endl;

}
