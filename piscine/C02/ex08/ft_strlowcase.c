/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:05:47 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/10 18:07:38 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<unistd.h>
char	*ft_strlowcase(char *str);

char	*ft_strlowcase(char *str)
{
	char	*ans;

	ans = str;
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
	return (ans);
}

/*int main()
{
	char a[] = "abcD0";
	write(1, ft_strlowcase(a), 5);
	return 0;
}*/
