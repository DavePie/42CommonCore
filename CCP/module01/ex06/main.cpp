/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:19:17 by marvin            #+#    #+#             */
/*   Updated: 2023/12/05 14:21:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char*av[])
{
	if (ac != 2)
	{
		std::cout << "Invalid number of parameters" << std::endl;
		return (1);
	}
	Harl h = Harl();
	h.complain_above(av[1]);
	return (0);
}