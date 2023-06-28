/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:39:49 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/10 18:04:49 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<unistd.h>
char	*ft_strupcase(char *str);

char	*ft_strupcase(char *str)
{
	char	*ans;

	ans = str;
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
	return (ans);
}

/*int main()
{
	char a[] = "abcD0";
	write(1, ft_strupcase(a), 5);
	return 0;
}*/
