/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssra-chagri <youssra-chagri@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:06:14 by ychagri           #+#    #+#             */
/*   Updated: 2025/07/15 19:58:51 by youssra-cha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP__
#define SPAN_HPP__

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <exception>
#include <climits>

class Span
{
            
            unsigned int        _size;
            std::vector<int>    _numbers;

    
    public :

            Span( void );
            Span( unsigned int N);
            Span( const Span& Other );
            Span &operator=( const Span& Other );
            ~Span ( void );

            void         addNumber( const int num );
            unsigned int shortestSpan( void );
            unsigned int longestSpan( void );

            template <typename iterator>
            void        addRange( iterator begin, iterator end )
        {
                if (std::distance(begin, end) + _numbers.size() > _size)
                    throw std::exception();
                    
                for (iterator it = begin; it != end; ++it)
                {
                    addNumber(*it);
                } 
        }               
                
        
};



#endif