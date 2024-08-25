/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:19:30 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/23 16:11:40 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <vector>
class PmergeMe
{
	private:
		PmergeMe(){};
		~PmergeMe(){};
		PmergeMe(PmergeMe const &other){(void)other;};
		PmergeMe &operator=(PmergeMe const &other){(void)other; return *this;};

		static void merge(std::vector<int> &arr, size_t left, size_t mid, size_t right);
		static void merge(std::deque<int> &arr, size_t left, size_t mid, size_t right);
	public:
		static void merge_sort(std::vector<int> &arr, size_t left, size_t right);
		static void merge_sort(std::deque<int> &arr, size_t left, size_t right);

};
