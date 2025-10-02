#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main() 
{
     std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);
    try {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Found in vector : " << *it << std::endl;
        it = easyfind(vec, 100);
        std::cout << "Found : " << *it << std::endl; 
    } catch (const std::exception& e) {
        std::cout << "vector test : " << e.what() << std::endl;
    }


    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);
    try 
    {
        std::list<int>::iterator it_lst = easyfind(lst, 15);
        std::cout << "Found in list: " << *it_lst << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cout << "List test" << e.what() << std::endl;
    }


    std::deque<int> deq;
    deq.push_back(1);
    deq.push_back(2);
    deq.push_back(3);
    deq.push_back(2);
    try {
        std::deque<int>::iterator it = easyfind(deq, 2);
        std::cout << "Found 2 in deque: " << *it << std::endl;

        it = easyfind(deq, 10); 
        std::cout << "Found 10 in deque: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "deque test : " << e.what() << std::endl;
    }


    std::vector<int> emptyV;
    try {
        std::vector<int>::iterator it = easyfind(emptyV, 1);
        std::cout << "Found in empty vector: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Empty vector test :" << e.what() << std::endl;
    }

    const int arr[] = {10, 20, 30};
    const std::vector<int> cv(arr, arr + 3);

    std::vector<int>::const_iterator it = easyfind(cv, 20);
    std::cout << *it << std::endl;
}