#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm> 
#include <iostream>

class Span
{
private:
    unsigned int N;                 
    std::vector<int> numbers;

public:
    Span(unsigned int N);
    ~Span();

    Span(const Span& other);
    Span& operator=(const Span& other);

    void addNumber(int number); 

    int shortestSpan() const;
    int longestSpan() const;

    template <typename InputIt>
    void addRNumber(InputIt begin, InputIt end)
{
    size_t rangeSize = std::distance(begin, end);

    if (numbers.size() + rangeSize > N)
        throw std::overflow_error("Span is full");

    numbers.insert(numbers.end(), begin, end);
}
};

#endif
