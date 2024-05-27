/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:10:16 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/12 15:39:47 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<unistd.h>
char	*ft_strcapitalize(char *str);

char	*ft_strcapitalize(char *str)
{
	char	*ans;
	char	prev;

	prev = ' ';
	ans = str;
	while (*str != '\0')
	{
		if ((prev < 'a' || prev > 'z') && (prev < '0' || prev > '9')
			&& (prev < 'A' || prev > 'Z'))
		{
			if (*str >= 'a' && *str <= 'z')
				*str -= 32;
		}
		else if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		prev = *str;
		str++;
	}
	return (ans);
}

/*int main()
{
	char a[] = "aa bb lskjsd 34SDFLKJSDF dDDDdd   ";
	write(1, ft_strcapitalize(a), 60);
	return 0;
}*/
