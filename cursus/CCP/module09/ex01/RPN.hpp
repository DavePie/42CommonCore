/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:49:11 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/23 16:10:16 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <stack>
#include <sstream>
#include <iostream>

class RPN
{
	private:
		RPN(){};
		~RPN(){};
		RPN(RPN const & other){(void)other;};
		RPN &operator=(RPN const &other){(void)other; return *this;};

	public:
		static void eval(std::string input);
		static int mult(int a, int b)
		{
			return (a * b);
		}
		static int div(int a, int b)
		{
			return (a / b);
		}
		static int add(int a, int b)
		{
			return (a + b);
		}
		static int sub(int a, int b)
		{
			return (a - b);
		}
};