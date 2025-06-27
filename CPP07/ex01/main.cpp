/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 00:05:50 by ychagri           #+#    #+#             */
/*   Updated: 2025/06/27 01:18:36 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename type>
void    increment(type &data)
{
    data++;
}


void    print(const int &i)
{
    std::cout << i << std::endl;
}

void    printchar(const char &c)
{ 
    std::cout << c;;
}



int main()
{
    int arr[] = {1, 7, 3, 5, 7};
    size_t l = 5;
    
    std::string sep(50, '=');
    std::cout << sep << std::endl;
    
    ::iter(arr, l, print);
    ::iter(arr, l, increment<int>);
    
    std::cout << sep << std::endl;
    ::iter(arr, l, print);
    
    std::string str("abcdef");
    l = str.length();
    std::cout << sep << std::endl;
    
    ::iter(&str[0], l, printchar);
    std::cout << std::endl;      
    ::iter(&str[0], l, increment<char>);

    std::cout << sep << std::endl;
    ::iter(&str[0], l, printchar);
    

    std::cout << std::endl;
}