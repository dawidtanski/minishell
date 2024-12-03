/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:31:33 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/04/02 17:53:10 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	if (count && size && count > (UINT_MAX / size))
		return (NULL);
	temp = malloc(count * size);
	if (!temp)
		return (NULL);
	while (i < count * size)
	{
		temp[i] = 0;
		i++;
	}
	return (temp);
}

// int	main()
// {
// 	size_t		count;
// 	size_t		size;
// 	const char	*memsize;

// 	count = 2;
// 	size = 3;
// 	memsize = ft_calloc(count, size);
// 	printf("Allocated memory: %p\n", ft_calloc(count, size));
// 	printf("Memory size: %s\n", memsize);
// 	return (0);
// }