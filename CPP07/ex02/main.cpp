/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:19:51 by ychagri           #+#    #+#             */
/*   Updated: 2025/07/23 20:41:08 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    
    Array<int> arr1(5);
    Array<char> str1(26);
    Array<int> intArray;
    
    try
    {
        std::cout << intArray[0] << std::endl;
    
        int arr2[5] = {1, 2, 3, 4, 5};

        for(size_t i = 0; i < arr1.size(); i++)
            arr1[i] = arr2[i];
    
        for(size_t i = 0; i < arr1.size(); i++)
            std::cout << arr1[i] << std::endl;

        std::string    str2 = "HELLO FROM THE OTHER SIDE";
        for(size_t i = 0; i < str1.size(); i++)
            str1[i] = str2[i];

        for(size_t i = 0; i < str1.size(); i++)
            std::cout << str1[i];
        
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "U accessed an index that is out of bound !" << '\n';
    }

    return 0;
}