/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:19:35 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/23 15:41:35 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char*av[])
{
	if (ac < 2)
	{
		std::cout << "Error: please enter numbers to sort" << std::endl;
		return 1;
	}
	std::vector <int> input;
	std::deque <int> input2;
	for (int i = 1; i < ac; i++)
	{
		input.push_back(std::stoi(av[i]));
		input2.push_back(std::stoi(av[i]));
		if (input.back() < 0)
		{
			std::cout << "Error: invalid number" << std::endl;
			return 1;
		}
	}
	std::cout << "Before:\t";
	size_t i;
	for (i = 0; i < input.size() && i < 7; i++)
		std::cout << input[i] << " ";
	if (i != input.size())
		std::cout << "[...]";
	std::cout << std::endl;
	clock_t start = clock();
	PmergeMe::merge_sort(input, 0, input.size() - 1);
	double time1 = (double)(clock() - start) * 1000000 / CLOCKS_PER_SEC;
	
	std::cout << "After:\t";
	for (i = 0; i < input.size() && i < 7; i++)
		std::cout << input[i] << " ";
	if (i != input.size())
		std::cout << "[...]";
	std::cout << std::endl;
	start = clock();
	PmergeMe::merge_sort(input2, 0, input2.size() - 1);
	double time2 = (double)(clock() - start) * 1000000 / CLOCKS_PER_SEC;
	
	std::cout << "Time to process \t" << input.size() << " elements with vector : \t" << time1 << std::endl;
	std::cout << "Time to process \t" << input.size() << " elements with deque : \t" << time2 << std::endl;

	return 0;
}