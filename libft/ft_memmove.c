/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:44:46 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/03/26 20:25:09 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp_dest;
	char	*temp_src;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	temp_dest = (char *) dest;
	temp_src = (char *) src;
	i = 0;
	if (temp_dest > temp_src)
	{
		while (n--)
			temp_dest[n] = temp_src[n];
	}
	else
	{
		while (i < n)
		{
			temp_dest[i] = temp_src[i];
			i++;
		}
	}
	return (dest);
}

// int	main()
// {
// 	char	str1[] = "string test";
// 	char	str2[] = "string test";

// 	if (!strcmp(memmove(str1, str1 + 3, 5), ft_memmove(str2, str2 + 3, 5)) 
//	&& !strcmp(memmove(str1 + 3, str1, 5), ft_memmove(str2 + 3, str2, 5)))
// 		printf("OK\n");
// 	else
// 		printf("Failed (tests : ft_memmove(s, s + 3, 5) 
//		and ft_memmove(s + 3, s, 5)).\n");
// 	return (0);
// }