/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 00:46:21 by ychagri           #+#    #+#             */
/*   Updated: 2025/07/15 01:18:43 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void ) : _size(0) {}

Span::Span( unsigned int N ) : _size(N)
{
    _numbers.reserve(N);
}

Span::Span( const Span& Other )
{
    *this = Other;
}

Span&
Span::operator=( const Span& Other )
{
    if (this != &Other)
    {
        _size = Other._size;
        _numbers = Other._numbers;
    }
    return *this;
}

void     Span::addNumber( const int num )
{
    if (_numbers.size() == _size)
        throw std::exception();
    
    _numbers.push_back(num);
}

unsigned int
Span::shortestSpan( void )
{
    if (_numbers.size() < 2)
        throw std::exception();
    
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    
    unsigned int minSpan = INT_MAX;
    for (size_t i = 1; i < sorted.size(); ++i)
    {
        unsigned int span = sorted[i] - sorted[i - 1];
        minSpan = std::min(minSpan, span);
    }
    
    return minSpan;
}

unsigned int
Span::longestSpan( void )
{
    if (_numbers.size() < 2)
        throw std::exception();
    
    int minNum = *std::min_element(_numbers.begin(), _numbers.end());
    int maxNum = *std::max_element(_numbers.begin(), _numbers.end());
    
    return static_cast<unsigned int>(maxNum - minNum);
}

template <typename iterator>
void    Span::addRange( iterator begin, iterator end )
{
    if (std::distance(begin, end) + _numbers.size() > _size)
        throw std::exception();
        
    for (iterator it = begin; it != end; ++it)
    {
        addNumber(*it);
    } 
}
