/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 01:01:15 by ychagri           #+#    #+#             */
/*   Updated: 2025/07/11 01:42:42 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;

    vec.push_back(1);
    vec.push_back(12);
    vec.push_back(71);
    vec.push_back(19);
    vec.push_back(100);
    vec.push_back(761);

    int i = 14;
    std::vector<int>::iterator it =  easyfind(vec, i);

    if ( it == vec.end())
        std::cout << i << " Was not Found !!";
    else
        std::cout << *it << " was Found";
    
    std::cout << std::endl;
    
    return 0;
}