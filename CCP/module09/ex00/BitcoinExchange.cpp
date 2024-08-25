/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:10:15 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/23 15:51:35 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <time.h>
BitcoinExchange::BitcoinExchange(std::string file)
{
	std::ifstream infile(file);
	if (infile.fail())
	{
		std::cout << "Error: invalid file" << std::endl;
		return;
	}
	std::string line, word;
	Data d = {};
	std::getline(infile, line);
	while (std::getline(infile, line))
	{
		std::istringstream s(line);
		std::getline(s, word, ',') >> d.rate;
		if (!strptime(word.c_str(), "%Y-%m-%d", &d.time))
		{
			std::cout << "Error: invalid date in csv (ignored)" << std::endl;
			continue;
		}
		vals.push_front(d);
	}
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::validate_entry(std::string temp, std::string sep, double num, std::tm *time)
{
	if (!strptime(temp.c_str(), "%Y-%m-%d", time)){
		std::cout << "Error: Invalid date" << std::endl;
		return false;
	}
	if (num < 0 || num > 1000){
		std::cout << "Error: Number not in range [0, 1000]" << std::endl;
		return false;
	}
	if (sep != "|"){
		std::cout << "Error: Invalid seperator" << std::endl;
		return false;
	}
	return true;
}

void BitcoinExchange::convert_file(std::string file)
{
	std::ifstream infile(file);
	if (infile.fail())
	{
		std::cout << "Error: invalid file" << std::endl;
		return;
	}
	std::string line, sep;
	double num;
	std::getline(infile, line);
	while (std::getline(infile, line))
	{
			std::tm dateTime = {};

		std::istringstream s(line);
		std::string temp;
		s >> temp >> sep >> num;
		if (!validate_entry(temp, sep, num, &dateTime))
			continue;
		find_entry(dateTime, num);
	}
}

void BitcoinExchange::find_entry(std::tm time, double num)
{
	Data temp = {};
	bool found = false;
	std::list<Data>::iterator it;
	for (it = vals.begin(); it != vals.end(); it++)
	{
		Data t = *it;
		if (difftime(mktime(&t.time), mktime(&time)) <= 0
			&& difftime(mktime(&t.time), mktime(&temp.time)) >= 0)
		{
			temp = t;
			found = true;
		}
	}
	if (found)
	{
		std::cout << time.tm_year + 1900 << "-";
		if (time.tm_mon + 1 < 10)
			std::cout << "0";
		std::cout << time.tm_mon + 1 << "-";
		if (time.tm_mday < 10)
			std::cout << "0";
		std::cout << time.tm_mday
			<< " => " << num << " = " << (num * temp.rate) << std::endl;
	}
	else
		std::cout << "Error: Lower or equal date not found" << std::endl;
	
}

