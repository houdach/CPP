#include "Zombie.hpp"

int main ()
{
    int i = 0 ;
   Zombie *zombie = zombieHorde(10, "Foo");
   while (i < 10)
   {
    zombie[i].announce();
    i++;
   }
   delete [] zombie;
   return (0);

}