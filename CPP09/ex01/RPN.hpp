/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuury <yuury@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:59:36 by yuury             #+#    #+#             */
/*   Updated: 2025/10/24 20:37:21 by yuury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>
#include <algorithm>

class RPN
{
        std::stack<int> _stack;

        RPN( const RPN &other );
        RPN& operator=( const RPN &other );
        
    public:
    
        RPN( void );
        ~RPN( void );
    
        void    RPNcalculator(const std::string &expression);
    
};