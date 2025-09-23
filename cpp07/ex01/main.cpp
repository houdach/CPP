#include <iostream>
#include "iter.hpp"

template <typename T>
void printElement(T const &x) {
    std::cout << x << " | ";
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::string strArr[] = {"apple", "banana", "cherry"};

    std::cout << "Int array: ";
    iter(arr, 5, printElement<int>);
    std::cout << std::endl;

    std::cout << "String array: ";
    iter(strArr, 3, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}
