#include "Zombie.hpp"

int main ()
{
    Zombie zombie3("Loo");
    Zombie *zombie2=newZombie("Boo");
   randomChump("Foo");
   zombie2->announce();
   zombie3.announce();
   delete(zombie2);

}