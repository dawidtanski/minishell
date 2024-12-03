/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:13:37 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/03/22 19:42:02 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == 0)
		return ((char *) big);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (big[i + j] == little[j] && big[i + j] && i + j < len)
				j++;
			if (little[j] == '\0')
				return ((char *) big + i);
		}
		i++;
	}
	return (0);
}

// int	main()
// {
// 	printf("ft_strnstr(\"bonjour\", \"ou\", 13) : our : %s\n", 
//	ft_strnstr("bonjour", "ou", 13));
// 	printf("ft_strnstr(\"bonjour\", \"njo\", 4) : (null) : %s\n", 
//	ft_strnstr("bonjour", "njo", 4));
// 	printf("ft_strnstr(\"bonjour\", \"njo\", 5) : njour : %s\n", 
//	ft_strnstr("bonjour", "njo", 5));
// 	return (0);
// }