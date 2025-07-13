/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:06:14 by ychagri           #+#    #+#             */
/*   Updated: 2025/07/13 21:53:22 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP__
#define SPAN_HPP__

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>


class Span
{
            
            unsigned int    _size;
            unsigned int    _N;

    
    public :

            Span( void );
            Span( unsigned int N);
            Span( const Span& Other );
            Span &operator=( const Span& Other );
            ~Span ( void );

            void         addNumber( int num );
            unsigned int shortestSpan( void );
            unsigned int longestSpan( void );
            
            
};



#endif