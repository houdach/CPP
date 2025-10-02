#include "Span.hpp"
int main()
{
    Span sp = Span(10);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span sp2(3);
        sp2.addNumber(42);
        try {
            sp2.shortestSpan();
        } catch (const std::exception& e) {
            std::cout << "Test 2 Exception: " << e.what() << std::endl;
        }
    
    Span sp3(2);
        sp3.addNumber(1);
        sp3.addNumber(2);
        try {
            sp3.addNumber(3);
        } catch (const std::exception& e) {
            std::cout << "Test 3 Exception: " << e.what() << std::endl; 
        }
    
     std::vector<int> nums;
        for (int i = 0; i < 10000; ++i)
            nums.push_back(i * 4);

        Span sp4(10000);
        try 
        {
            sp4.addRNumber(nums.begin(), nums.end());
        }
        catch (const std::exception& e) {
            std::cout << "Range Exception: " << e.what() << std::endl; 
        }
        try
        {
            std::cout << "Test 4 - Shortest: " << sp4.shortestSpan() << std::endl; 
            std::cout << "Test 4 - Longest: " << sp4.longestSpan() << std::endl;   

        }
        catch (const std::exception& e) {
            std::cout << "Range Exception: " << e.what() << std::endl;
        }

    return(0);
}