/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:25:55 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/23 14:17:56 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

typedef int (*op)(int a, int b);

void RPN::eval(std::string input)
{
	std::string a = "+-*/";
	op t[4] = {add, sub, mult, div};
	std::stack<int>nums;
	std::istringstream s(input);
	std::string temp;

	while (std::getline(s, temp, ' '))
	{
		if (temp.size() != 1) {
			std::cout << "Error: invalid value: '"<< temp << "'" <<std::endl;
			return;
		}
		if (std::isdigit(temp[0])) {
			nums.push(temp[0] - '0');
			continue;
		}
		size_t i;
		for (i = 0; i < a.length(); i++) {
			if (a[i] == temp[0]) {
				if (nums.size() < 2) {
					std::cout << "Error: Invalid operator: " << temp << std::endl;
					return;
				}
				int a = nums.top();
				nums.pop();
				int b = nums.top();
				nums.pop();
				nums.push(t[i](b, a));
				break;
			}
		}
		if (i == a.length()) {
			std::cout << "Error: unregconized symbol: "<< temp << std::endl;
			return;
		}
	}
	if (nums.size() != 1) {
		std::cout << "Error: invalid number of operators" << std::endl;
		return;
	}
	std::cout << nums.top() << std::endl;
}