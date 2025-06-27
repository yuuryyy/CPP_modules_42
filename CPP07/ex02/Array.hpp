/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:42:46 by ychagri           #+#    #+#             */
/*   Updated: 2025/06/27 19:40:00 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

template<typename T>
class Array
{

    T       *_data;
    size_t  _size;

    public:

        Array( void );
        Array( unsigned int n );
        Array( const Array& Other );
        Array& operator=( const Array& other );
        ~Array( void );

        T&        operator[]( size_t index );
        const T&  operator[]( size_t index ) const;

        size_t  size( void ) const;
};


#include "Array.tpp"