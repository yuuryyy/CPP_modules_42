/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:28:04 by ychagri           #+#    #+#             */
/*   Updated: 2025/07/16 00:34:31 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


int main()
{

    srand(static_cast<unsigned int>(time(0)));
    std::string sep(50, '*');

    {
        Span sp = Span(5);
        
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        std::cout << sep << std::endl;

    }
// *****************************************************


    int arr[6] = {1,3, 3, 2, 0, 232};
    std::vector<int> vec;
    vec.reserve(10000);

    for (int i = 0; i < 10000; i++)
        vec.push_back(rand() % 500000);
    
    vec[10] = INT_MAX;
    
    try
    {
       Span sp1(10006);

       sp1.addRange(arr, arr + 6);
       
        std::cout << sp1.shortestSpan() << std::endl;
        std::cout << sp1.longestSpan() << std::endl;
        
        std::cout << sep << std::endl;
        // *****************************************************

        sp1.addRange(vec.begin(), vec.end());

        std::cout << sp1.shortestSpan() << std::endl;
        std::cout << sp1.longestSpan() << std::endl;
        
        std::cout << sep << std::endl;
        // *****************************************************

        sp1.addNumber(8);

    }
    
    catch( const std::exception& e )
    {
        std::cerr << "Span is out of range !" << std::endl;
    }
// *****************************************************

    try
    {
        Span    sp2;

        sp2.addNumber(5);

        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
        
        std::cout << sep << std::endl;
    }

    catch ( const std::exception& e )
    {
        std::cerr << "Span is out of range !" << std::endl;
       
    }
    
    return 0;
}
