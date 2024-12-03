/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:47:42 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/03/25 22:12:00 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *) s;
	while (n > 0)
	{
		*(temp++) = (unsigned char) c;
		n--;
	}
	return (s);
}

// int	main()
// {
// 	char s[100] = "aaaaa";
// 	char sbis[100] = "aaaaa";
// 	if (!strcmp(memset(s, 'z', 3), ft_memset(sbis, 'z', 3)))
// 		printf("OK\n");
// 	else
// 		printf("Failed : expected '%s', got '%s'.\n", s, sbis);
// 	return (0);
// }