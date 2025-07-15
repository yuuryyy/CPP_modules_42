/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:06:14 by ychagri           #+#    #+#             */
/*   Updated: 2025/07/15 01:06:20 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP__
#define SPAN_HPP__

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <exception>

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
            void        addRange( iterator begin, iterator end );
        
};



#endif