/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 00:23:54 by ychagri           #+#    #+#             */
/*   Updated: 2025/07/24 00:12:50 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    { 
        std::string sep(50, '*');

        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);
        
        std::cout << sep << std::endl;
        std::cout << mstack.top() << std::endl;
        
        mstack.pop();
        std::cout << sep << std::endl;
        
        std::cout << mstack.size() << std::endl;
        
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        
        ++it;
        --it;
        std::cout << mstack.size() << std::endl;

        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

// ###############################################################

    { 
        std::string sep(50, '*');

        std::vector<int> mstack;

        mstack.push_back(5);
        mstack.push_back(17);
        
        std::cout << sep << std::endl;
        std::cout << mstack.back() << std::endl;
        
        mstack.pop_back();
        std::cout << sep << std::endl;
        
        std::cout << mstack.size() << std::endl;
        
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        //[...]
        mstack.push_back(0);

        std::vector<int>::iterator it = mstack.begin();
        std::vector<int>::iterator ite = mstack.end();
        
        ++it;
        --it;
        std::cout << mstack.size() << std::endl;

        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

    }
    
    return 0;
}