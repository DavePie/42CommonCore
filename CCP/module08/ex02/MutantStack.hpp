/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:50:35 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/19 17:45:20 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>
#include <iterator>
template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(){}
        ~MutantStack(){}
		MutantStack &operator=(const MutantStack &other)
		{
			this->std::stack<T, Container>::operator=(other);
			return *this;
		}
		typedef typename Container::iterator iterator;
		MutantStack(const MutantStack &stack)
		{
			*this = stack;
		}
		iterator begin()
		{
			return this->c.begin();
		}
		iterator end()
		{
			return this->c.end();
		}
};
#endif