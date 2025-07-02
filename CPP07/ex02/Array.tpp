/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssra-chagri <youssra-chagri@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:49:34 by ychagri           #+#    #+#             */
/*   Updated: 2025/06/29 00:30:18 by youssra-cha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

template<typename T>
Array<T>::Array( void ):_size(1)
{
    _data = new T[0]();
}

template<typename T>
Array<T>::Array( unsigned int n ): _data(NULL), _size(n)
{
    if (_size > 0)
        _data = new T[n]();
}

template<typename T>
Array<T>::Array( const Array& Other )
{
    if (this != &Other)
        this = Other;
}

template<typename T>
Array<T>&
Array<T>::operator=( const Array& Other )
{
    if (this != &Other)
    {
        if (this->_data)
            delete[] this->_data;
        this->_size = Other._size;
        if (_size > 0)
        {
            this->_data = new T[Other._size]();
            for (size_t i = 0; i < Other._size; i++)
            {
                this->_data[i] = Other->_data[i];
            }
        }

    }

    return *this;
}

template<typename T>
size_t  Array<T>::size( void ) const
{
    return this->_size;
}

template<typename T>
Array<T>::~Array( void )
{
    if (this->_data)
        delete[] _data;
}

template<typename T>
T&
Array<T>::operator[]( size_t index )
{
    if (index >= _size)
        throw std::exception();
    return _data[index];
}

template<typename T>
const T&
Array<T>::operator[]( size_t index ) const
{
    if (index >= _size)
        throw std::exception();
    return _data[index];
}
