#include "Span.hpp"

Span::Span(unsigned int N)
{
    if (N == 0)
        throw std::invalid_argument("Span size must be > 0");
    else
        this->N = N;
}
Span::~Span()
{
}

Span::Span(const Span& other) : N(other.N), numbers(other.numbers)
{
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)  
    {
        this->N = other.N;             
        this->numbers = other.numbers; 
    }
    return *this; 
}

void Span::addNumber(int number)
{
    if (numbers.size() < N)
        numbers.push_back(number);
    else
        throw std::overflow_error("span is full");
}

int Span::shortestSpan() const
{
   if (numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");

    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = sorted[1] - sorted[0];

    for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end() - 1; ++it)
    {
        int diff = *(it + 1) - *it;
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;

}

int Span::longestSpan() const
{
    if (numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");
   int maxSpan = *std::max_element(numbers.begin(), numbers.end()) -
              *std::min_element(numbers.begin(), numbers.end());
    return(maxSpan);
}
