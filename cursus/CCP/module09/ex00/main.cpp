/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:40:32 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/23 16:01:45 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char*av[])
{
	if (ac != 2)
	{
		std::cout << "Invalid number of parameters" << std::endl;
		return (1);
	}
	BitcoinExchange a("./data.csv");
	a.convert_file(av[1]);
	(void) a;
	return (0);
}