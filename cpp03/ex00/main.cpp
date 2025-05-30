#include "ClapTrap.hpp"

int main()
{
    ClapTrap d("BotD");
    ClapTrap a("BotA");
    d.attack("enemy");
    d.takeDamage(5);
    d.beRepaired(3);
    ClapTrap b(a);
    ClapTrap e("BotE");      
    e = b;              
    return 0;
}
