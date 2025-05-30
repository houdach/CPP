#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    FragTrap d("BotD");
    FragTrap a("BotA");
    d.attack("enemy");
    d.takeDamage(5);
    d.beRepaired(3);
    d.highFivesGuys();
    FragTrap b(a);
    FragTrap e("BotE");      
    e = b;              
    return 0;
}
