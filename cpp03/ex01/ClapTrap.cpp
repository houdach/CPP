 #include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    Name = name;
    Hit_points = 10;
    Energy_points = 10;
    Attack_damage = 0;
    std::cout<<"ClapTrap constructor has been called"<<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
     std::cout<<"copy constructor called"<<std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if(this != &other)   
    {
        this->Name = other.Name;
        this->Hit_points = other.Hit_points;
        this->Energy_points = other.Energy_points;
        this->Attack_damage = other.Attack_damage;
        std::cout<<"copy assignement constructor called"<<std::endl;
    }
    return(*this);
}

void ClapTrap::attack(const std::string& target)
{
    if(Energy_points == 0 || Hit_points == 0)
    {
        std::cout << "ClapTrap " << Name << " has no energy or is dead and cannot attack!" << std::endl;
        return ;
    }
    Energy_points--;
    std::cout  << "ClapTrap "<<Name<<" attacks "<<target<<" causing "<<Attack_damage<<" points of damage!"<<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (Hit_points == 0) {
        std::cout << "ClapTrap " << Name << " is already destroyed!" << std::endl;
        return;
    }
    if (amount >= Hit_points)
        Hit_points = 0;
    else 
        Hit_points -= amount;
    std::cout << "ClapTrap " << Name << " takes " << amount << " of damage!" <<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(Energy_points == 0 || Hit_points == 0)
    {
        std::cout<<"ClapTrap " << Name<< " has no energy or is dead and cannot be repaired"<<std::endl;
        return ;
    }
    Energy_points--;
    Hit_points+=amount;
    std::cout << "ClapTrap " << Name << " is repaired for "<< amount << " hit points!" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout<<"ClapTrap destructor has been called"<<std::endl;
}
 