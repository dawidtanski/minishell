/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:46:35 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/03/27 21:02:04 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ss;
	unsigned char	cc;
	size_t			i;

	ss = (unsigned char *) s;
	cc = (unsigned char) c;
	i = 0;
	if (!s)
		return (NULL);
	while (i < n)
	{
		if (ss[i] == cc)
			return ((void *) &ss[i]);
		i++;
	}
	return (NULL);
}

// int	main()
// {
// 	if (memchr("source", 'r', 2) == ft_memchr("source", 'r', 2) && 
//	!strcmp(memchr("source", 'r', 5), ft_memchr("source", 'r', 5)))
// 		printf("OK\n");
// 	else
// 		printf("Failed.\n");
// 	return (0);
// }