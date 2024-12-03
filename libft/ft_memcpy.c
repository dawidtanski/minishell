/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:43:59 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/03/26 18:03:03 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	temp_dest = (unsigned char *) dest;
	temp_src = (unsigned char *) src;
	while (n > 0)
	{
		*(temp_dest++) = *(temp_src++);
		n--;
	}
	return (dest);
}

// int	main()
// {
// 	char	*str_dest;
// 	char	*str_src;

// 	str_dest = "test1";
// 	str_src = "test1";
// 	printf("Original function: %p\n", memcpy(str_dest, str_src, 4));
// 	printf("ft_memcpy: %p\n", ft_memcpy(str_dest, str_src, 4));
// 	// Second test
// 	char	s[100] = "aaaaa";
// 	char	sbis[100] = "aaaaa";
// 	strcpy(sbis, s);
// 	if (!strcmp(memcpy(s, "source", 3), ft_memcpy(sbis, "source", 3)) && 
//	!strcmp(memcpy(s, "other source", 8), ft_memcpy(sbis, "other source", 8)))
// 		printf("OK\n");
// 	else
// 		printf("Failed : expected '%s', got '%s'.\n", s, sbis);
// 	return (0);
// }