#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    const Animal* animals[4];
    for (int i = 0; i < 2; ++i)
        animals[i] = new Dog();
    
    for (int i = 2; i < 4; ++i)
        animals[i] = new Cat();

    for (int i = 0; i < 4; ++i)
        animals[i]->makeSound();

    for (int i = 0; i < 4; ++i)
        delete animals[i];
    
    Dog dog1;
    dog1.setBrainIdea(0, "Chase the cat");
    dog1.setBrainIdea(1, "Eat bones");

    Dog dog2(dog1);  // Copy constructor
    dog2.setBrainIdea(0, "Sleep all day");

    Dog dog3;
    dog3 = dog1;
    dog3.setBrainIdea(1, "Play fetch");

    std::cout << "dog1 brain idea 0: " << dog1.getBrainIdea(0) << std::endl;
    std::cout << "dog2 brain idea 0: " << dog2.getBrainIdea(0) << std::endl;
    std::cout << "dog1 brain idea 1: " << dog1.getBrainIdea(1) << std::endl;
    std::cout << "dog3 brain idea 1: " << dog3.getBrainIdea(1) << std::endl;

    return 0;
}