/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:37:14 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/07 15:44:43 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAINHPP
# define BRAINHPP
# include <string>
# include <iostream>
class Brain
{
	protected:
		std::string ideas[100];
	public:
		Brain();
		Brain(Brain& other);
		~Brain();
		Brain& operator=(Brain& other);
};
#endif