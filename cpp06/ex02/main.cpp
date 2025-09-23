#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

int main() {
    srand(time(NULL));

    for (int i = 0; i < 5; ++i) {
        Base* p = generate();

        std::cout << "identify(Base*): ";
        identify(p);

        std::cout << "identify(Base&): ";
        identify(*p);

        delete p;
        std::cout << "-----\n";
    }
    return 0;
}
