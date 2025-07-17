/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:31:41 by ychagri           #+#    #+#             */
/*   Updated: 2025/07/18 00:39:07 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <deque>
#include <iterator>
#include <string>

template<typename T, typename Countainer = std::deque<T> >
class MutantStack :  public std::stack<T, Countainer>
{
        public:
        
                MutantStack( void ) : std::stack<T, Countainer>(){};
                MutantStack( const MutantStack& Other ) : std::stack<T, Countainer>(Other){};
                MutantStack& operator=( const MutantStack& Other )
                {
                        if (this != &Other)
                                std::stack<T, Countainer>::operator=(Other);
                        return *this;
                };

                ~MutantStack( void ){};

                typedef typename Countainer::iterator                   iterator;
                typedef typename Countainer::const_iterator             const_iterator;
                typedef typename Countainer::reverse_iterator           reverse_iterator;
                typedef typename Countainer::const_reverse_iterator     const_reverse_iterator;

                iterator        begin( void )
                {
                        return this->c.begin();
                };
                
                iterator        end( void )
                {
                        return this->c.end();
                };
                
                
                const_iterator        begin( void ) const
                {
                        return this->c.begin();
                };
                const_iterator        end( void ) const
                {
                        return this->c.end();
                };
                
                                
                reverse_iterator        rbegin( void )
                {
                        return this->c.rbegin();
                };

                reverse_iterator        rend( void )
                {
                        return this->c.rend();
                };
                
                                
                const_reverse_iterator        rbegin( void ) const
                {
                        return this->c.rbegin();
                };
                
                const_reverse_iterator        rend( void ) const
                {
                        return this->c.rend();
                };

};
