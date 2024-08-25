/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:09:50 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/23 15:13:31 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <list>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <ctime>

class BitcoinExchange
{
	private:
		struct Data
		{
			double rate;
			std::tm time;
		};
		std::list<Data> vals;
		BitcoinExchange();
		bool validate_entry(std::string temp, std::string sep, double num, std::tm *time);
		void find_entry(std::tm time, double num);
	public:
		BitcoinExchange(std::string file);
		BitcoinExchange(BitcoinExchange const & other){vals = other.vals;};
		BitcoinExchange &operator=(BitcoinExchange const &other){vals = other.vals; return *this;};

		~BitcoinExchange();
		void convert_file(std::string file);
};