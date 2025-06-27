/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 00:05:39 by ychagri           #+#    #+#             */
/*   Updated: 2025/06/27 00:05:42 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP__
#define WHATEVER_HPP__

#include <iostream>

template<typename type>
void swap(type &a, type &b)
{
    type c = a;
    a = b;
    b = c;
}

template<typename type>
type min(type a, type b)
{
    return (b > a) ? a : b;
}

template<typename type>
type max(type a, type b)
{
    return (a > b) ? a : b;
}

#endif