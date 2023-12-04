/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:24:24 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/04 17:35:42 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;
	std::cout << &str << " : " << str << std::endl;
	std::cout << ptr << " : " << *ptr << std::endl;
	std::cout << &ref << " : " << ref << std::endl;
	return (0);
}