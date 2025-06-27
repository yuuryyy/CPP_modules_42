/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 00:05:48 by ychagri           #+#    #+#             */
/*   Updated: 2025/06/27 00:52:24 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP__
#define ITER_HPP__


#include <iostream>
#include <string>

template<typename type, typename fun>
void   iter(type* arr, size_t size, fun f)
{
    for (size_t i = 0; i < size; i++)
        f(arr[i]);
}

#endif