/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuury <yuury@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:33:41 by yuury             #+#    #+#             */
/*   Updated: 2025/10/24 22:14:44 by yuury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( void ){}


RPN::~RPN( void ) {}


RPN::RPN( const RPN &other )
{
    *this = other;
}

RPN&
RPN::operator=( const RPN &other )
{
    if (this != &other)
        this->_stack = other._stack;
    return *this;
}

void
RPN::RPNcalculator( const std::string &expression )
{
    for (size_t i = 0; i < expression.size(); i++)
    {

        if (isdigit(expression[i]))
            this->_stack.push(expression[i] - '0');
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*'  || expression[i] == '/' )
        {
            if (this->_stack.size() < 2)
            {
                std::cerr << "Error: Invalid Characters/ordering!";
                return ;                
            }
            int a = this->_stack.top();
            this->_stack.pop();
            int b = this->_stack.top();
            this->_stack.pop();
            if (expression[i] == '+')
                this->_stack.push(b + a);
            else if (expression[i] == '-')
                this->_stack.push(b - a);
            else if (expression[i] == '*')
                this->_stack.push(b * a);
            else
            {
                if (a == 0)
                {
                    std::cerr << "Error: Division by 0!" << std::endl;
                    return ;
                }
                this->_stack.push(b / a);
            }
        }
        else if (expression[i] != ' ')
        {
            std::cerr << "Error: Invalid Characters/ordering!";
            return ;
        }

    }
    if (this->_stack.size() != 1)
    {
        std::cerr << "Error: Invalid RPN expression (final stack size is not 1)!";
        return ;
        
    }
    std::cout << this->_stack.top() << std::endl;
    this->_stack.pop();
}
