/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 01:13:02 by ychagri           #+#    #+#             */
/*   Updated: 2025/07/11 01:37:55 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND__
#define EASY_FIND__

#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>

template<typename T>
typename T::iterator    easyfind(T &countainer, const int val)
{
    typename T::iterator it = countainer.begin();
    
    for (; it != countainer.end(); it++)
        if (*it == val)
            break;
    return it;
}

#endif