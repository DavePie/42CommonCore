/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:39:13 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/12 18:54:15 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
class Span
{
	private:
		int *a;
		unsigned int size;
		unsigned int l;
	public:
		Span(unsigned int size);
		~Span();
		Span(const Span & other);
		Span &operator=(const Span &other);

		void addNumber(int num);
		int shortestSpan();
		int longestSpan();
};
#endif