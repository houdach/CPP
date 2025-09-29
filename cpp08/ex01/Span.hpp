#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm> // for sort, min_element, etc.

class Span
{
private:
    unsigned int _N;                 // Maximum capacity
    std::vector<int> _numbers;       // Container to store integers

public:
    // Constructor / Destructor
    Span(unsigned int N);
    ~Span();

    // Copy constructor and assignment operator
    Span(const Span& other);
    Span& operator=(const Span& other);

    // Add numbers
    void addNumber(int number); // add a single number

    template <typename InputIt>
    void addNumber(InputIt begin, InputIt end); // add a range of numbers

    // Compute spans
    int shortestSpan() const;
    int longestSpan() const;
};

#endif
