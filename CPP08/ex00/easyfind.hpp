/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 01:13:02 by ychagri           #+#    #+#             */
/*   Updated: 2025/07/23 23:47:00 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND__
#define EASY_FIND__

#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <exception>

template<typename T>
typename T::iterator    easyfind(T &countainer, const int &val)
{
    typename T::iterator it = std::find(countainer.begin(), countainer.end(), val);

    if (it == countainer.end())
        throw std::exception();
    return it;
}

#endif