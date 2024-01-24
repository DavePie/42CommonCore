/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:51:08 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/23 13:57:20 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char*av[])
{
	if (ac != 2)
	{
		std::cout << "Error: invalid number of arguments" << std::endl;
		return (1);
	}
	RPN::eval(av[1]);
	return (0);
}