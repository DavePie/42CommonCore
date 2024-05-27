/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:19:32 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/05 16:01:47 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int replace(std::string file_name, std::string s1, std::string s2)
{
	
	std::ifstream input(file_name);
	if (!input){
		std::cout << "Invalid input file" << std::endl;
		return (1);
	}
	std::ofstream output(file_name+".replace");
	if (!output){
		std::cout << "Unable to create output file" << std::endl;
		return (1);
	}
	std::string cur;
	while (std::getline(input, cur))
	{
		size_t pos = cur.find(s1);
		while (pos != std::string::npos)
		{
			cur = cur.substr(0, pos) + s2
				+ cur.substr(pos + s1.length(), cur.length() - pos - s1.length());
			pos = cur.find(s1, pos + s2.length());
		}
		output << cur << '\n';
	}
	return (0);
}

int main(int ac, char *av[])
{
	if (ac != 4){
		std::cout << "Invalid number of parameters" << std::endl;
		return (1);
	}
	return replace(std::string(av[1]), std::string(av[2]), std::string(av[3]));
}