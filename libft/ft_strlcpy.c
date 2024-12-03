/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:08:14 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/03/22 20:00:21 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < size)
		ft_memcpy(dest, src, src_len + 1);
	else if (size != 0)
	{
		ft_memcpy(dest, src, size - 1);
		dest[size - 1] = '\0';
	}
	return (src_len);
}

// int	main()
// {
// 	char *c1 = "source";
// 	char c2[] = "destination";
// 	char c3[] = "destination";
// 	printf("6, sour : %lu, %s\n", ft_strlcpy(c2, c1, 5), c2);
// 	printf("6, source : %lu, %s\n", ft_strlcpy(c3, c1, 8), c3);
// 	return (0);
// }