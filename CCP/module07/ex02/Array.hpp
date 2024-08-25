/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:49:53 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/24 10:11:27 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
template <class T>
class Array
{
	private:
		T * a;
		unsigned int n;
	public:
		Array(): a(new T[0]), n(0){};
		Array(unsigned int size): a(new T[size]), n(size){};
		Array(const Array & other): a(new T[other.n]), n(other.n)
		{
			for (unsigned int i = 0; i < n; i++)
				a[i] = other.a[i];
		}
		Array	&operator = (const Array &other)
		{
			delete[] a;
			a = new T[other.n];
			n = other.n;
			for (unsigned int i = 0; i < n; i++)
				a[i] = other.a[i];
			return *this;
		}
		
		T	&operator [] (unsigned int index) const
		{
			if (index >= n)
				throw new std::exception();
			return a[index];
		}

		unsigned int size()
		{
			return n;
		}

		~Array()
		{
			delete[] a;
		}
};
#endif
