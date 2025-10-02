#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm> 

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

    template <typename InputIt>
    void addNumber(InputIt begin, InputIt end)
    {
        int range_size = end - begin;
        if(numbers.size() + range_size > N)
            throw std::out_of_range("span is full");
        numbers.insert(numbers.end(), begin, end);
    }

    int shortestSpan() const;
    int longestSpan() const;
};

#endif
