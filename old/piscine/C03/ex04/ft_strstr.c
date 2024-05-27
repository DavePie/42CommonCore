/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:58:32 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/12 11:32:22 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
char	*ft_strstr(char *str, char *to_find);

char	*ft_strstr(char *str, char *to_find)
{
	char	*temp_str;
	char	*temp_to_find;

	temp_str = str;
	temp_to_find = to_find;
	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		temp_str = str;
		temp_to_find = to_find;
		while (*temp_str == *temp_to_find)
		{
			temp_str++;
			temp_to_find++;
			if (*temp_to_find == '\0')
				return (str);
		}
		str++;
	}
	return (0);
}

/*int main(){
	char * a = "first of allzzzz";
	char * b = "all";
	printf("%s", ft_strstr(a, b));
	return 0;
}*/
