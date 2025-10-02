#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm> 

class Span
{
private:
    unsigned int _N;            
    std::vector<int> _numbers;      

public:
 
    Span(unsigned int N);
    ~Span();

    Span(const Span& other);
    Span& operator=(const Span& other);

    void addNumber(int number); 

    template <typename InputIt>
    void addNumber(InputIt begin, InputIt end);

    int shortestSpan() const;
    int longestSpan() const;
};

#endif
