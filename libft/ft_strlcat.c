/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:04:28 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/03/25 21:30:03 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dest_len >= size)
		dest_len = size;
	if (dest_len == size)
		return (size + src_len);
	if (src_len < size - dest_len)
		ft_memcpy(dest + dest_len, src, src_len + 1);
	else
	{
		ft_memcpy(dest + dest_len, src, size - dest_len - 1);
		dest[size - 1] = '\0';
	}
	return (dest_len + src_len);
}

// int	main()
// {
// 	char *c1 = "source";
// 	char d2[100] = "destination";
// 	char d3[100] = "destination";
// 	char d4[100] = "destination";
// 	char d5[100] = "dest";
// 	char d6[100] = "dest";
// 	char d7[100] = "dest";
// 	printf("11, destination : %lu, %s\n", ft_strlcat(d2, c1, 5), d2);
// 	printf("14, destination : %lu, %s\n", ft_strlcat(d3, c1, 8), d3);
// 	printf("17, destinations : %lu, %s\n", ft_strlcat(d4, c1, 13), d4);
// 	printf("10, dest : %lu, %s\n", ft_strlcat(d5, c1, 5), d5);
// 	printf("10, destsou: %lu, %s\n", ft_strlcat(d6, c1, 8), d6);
// 	printf("10, destsource : %lu, %s\n", ft_strlcat(d7, c1, 13), d7);
// 	return (0);
// }