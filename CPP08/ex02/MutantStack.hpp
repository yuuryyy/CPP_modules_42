/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:31:41 by ychagri           #+#    #+#             */
/*   Updated: 2025/07/16 23:05:55 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>

template<typename T>
class MutantStack :  public std::stack<T>
{
    private:
        
    
    public:
        MutantStack();
        ~MutantStack();
};
