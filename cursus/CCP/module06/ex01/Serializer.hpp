/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:25:48 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/12 13:44:26 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include "Data.hpp"
# include <cstdint>
class Serializer
{
	private:
		Serializer(){};
	public:
		~Serializer(){};
		Serializer(Serializer const &other){(void)other;};
		Serializer &operator=(Serializer const &other){(void)other; return *this;};
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif