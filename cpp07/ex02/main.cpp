#include <iostream>
#include "Array.hpp"

int main() {
    Array<int> arr1(5);
    for (unsigned int i = 0; i < arr1.size(); i++)
        arr1[i] = i * 10;

    std::cout << "arr1: ";
    for (unsigned int i = 0; i < arr1.size(); i++)
        std::cout << arr1[i] << " ";
    std::cout << std::endl;

    Array<int> arr2 = arr1;  // copy constructor
    arr2[0] = 999;           // should not affect arr1

    std::cout << "arr1 after arr2 modified: ";
    for (unsigned int i = 0; i < arr1.size(); i++)
        std::cout << arr1[i] << " ";
    std::cout << std::endl;

    // Test out-of-bounds
    try {
        arr1[10] = 5;
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    Array<std::string> strArr(3);
    strArr[0] = "apple";
    strArr[1] = "banana";
    strArr[2] = "cherry";

    std::cout << "String array: ";
    for (unsigned int i = 0; i < strArr.size(); i++)
        std::cout << strArr[i] << " ";
    std::cout << std::endl;
    
    return 0;
}
