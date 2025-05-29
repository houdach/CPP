#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
   ClapTrap a("BotA");
   ScavTrap d("Botd");
    a.attack("Target");
    d.attack("enemy");
    a.takeDamage(5);
    a.beRepaired(3);
    ClapTrap b(a);
    ScavTrap e(d);      
    ClapTrap c("BotC");
    c = a;                
    return 0;
}
