#include "Span.hpp"

 Span::Span(unsigned int N)
 {}

 Span::~Span(){}
 Span::Span(const Span& other)
 {

 }
 Span& Span::operator=(const Span& other)
 {

 }

void Span::addNumber(int number)
{
    if(numbers.size() > N)
        throw std::out_of_range("span is full");
    numbers.push_back(number);
}

int Span::shortestSpan() const
{

}

int Span::longestSpan() const
{
   size_t maxSpan = ((*std::max_element(numbers.begin(), numbers.end())) - (*std::min_element(numbers.begin(), numbers.end())));
    return(maxSpan);
}